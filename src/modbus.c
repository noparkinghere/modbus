/**
 ***********************************************************************************************************************
 * Copyright (c) 2022
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
 * an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 *
 * @file        modbus.c
 *
 * @brief       
 *
 * @revision
 *          Date:           2022-09-26
 *          Author:         Damon
 *          Notes:
 *          1. 兼容了常用数据类型；short、long、float 和 double。
 *          2. 如果需要使用字符串，建议设置成 short 类型，方便统一处理，以免处理对齐问题，由用户应用程序进行拼接成原始数据。
 *          Date:           2023-02-20
 *          Author:         Damon
 *          Notes:
 *          1. 增加了合法性判断的宏定义开关，对于 ram 空间比较紧张，数据不叫多的应用可以关闭合法值判断，节省资源。
 *          Date:           2023-02-21
 *          Author:         Damon
 *          Notes:
 *          1. 增加回调函数，引入第三方协议，一个串口可以同时兼容 modbus 和其他协议。
 * @description
 ***********************************************************************************************************************
 */

#include <stdint.h>
#include "common.h"
#include "modbus.h"


/* 特殊数据处理策略 */
uint8_t old_modbus_addr = 1;
uint16  def_addr        = 0xF7;  // 默认地址


/* CRC 低位字节值表 */
static const unsigned char auchCRCLo[] = {
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

/* CRC高位字节值表*/
static const unsigned char auchCRCHi[] = {
        0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
        0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
        0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
        0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
        0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
        0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
        0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
        0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
        0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
        0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
        0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
        0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
        0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
        0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
        0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
        0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
        0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
        0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
        0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
        0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
        0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
        0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
        0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
        0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
        0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
        0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

/* CRC 校验码计算 */
uint16_t check_crc16(uint8_t *puchMsg, uint8_t iDataLen) {
    uint8_t uchCRCLo = 0xff;
    uint8_t uchCRCHi = 0xff;
    uint8_t uIndex;

    while (iDataLen--) {
        uIndex   = uchCRCLo ^ *puchMsg++;
        uchCRCLo = uchCRCHi ^ auchCRCLo[uIndex];
        uchCRCHi = auchCRCHi[uIndex];
    }
    return (uchCRCHi << 8 | uchCRCLo);
}


static void bind_reg(volatile RegGroup_t *reg) {
    /* 初始化快表，赋值 0xff，用于判定 */
    for (uint8_t i = 0; i < MAX_DATA_LEN; i++) {
        reg->fast_table[i] = 0xff; /* 创建快表帮助查询数据 */
    }
    /* G1 地址的绑定 */
    for (uint8_t i = 0; i < reg->valid_data_cnt; i++) {
        reg->fast_table[reg->data[i].addr % reg->start_addr] = i; /* 创建快表帮助查询数据 */
    }
}

/* 绑定数据，在程序初始化的时候执行 */
static void bind_p_and_addr(void) {
    for (uint8_t i = 0; i < REG_ALL_LEN; i++) {
        bind_reg(&g_reg[i]);
    }
}

/* modbus 协议初始化，包括数据等内容 */
void init_modbus(void) {
    g_modbus_addr = 0x01;
    bind_p_and_addr();
}


void opt_hardware(void) {

}

void offer_val(int *reg_num, RegGroup_t **reg_arr) {
    *reg_num = REG_ALL_LEN;
    *reg_arr = (RegGroup_t *) g_reg;
}


/*
准备发送的数据
len : 是整个 buffer 的数据长度
buffer ： 完整的缓存数据
*/
// TODO 错误返回时候的错误码
static uint8_t data_to_buff(volatile RegGroup_t *reg, uint16_t start, uint8_t len, uint8_t *buffer) {
    uint16_t read_reg_len = buffer[5];

    g_itest16 = start;
    g_itest16 = read_reg_len;
    g_itest16 = reg->end_addr;

    /* 起始位置不在合法范围内。 */
    if (start < reg->start_addr) {
        return FALSE;
    }

    /* 数据操作的位置超出可读写寄存器范围。 */
    if (start + read_reg_len - 1 > reg->end_addr) {
        return FALSE;
    }

    /* 起始位置指向为某个数据的中间值则不合法，快表用来判断数据合法性 */
    uint8_t addr_start = (start % reg->start_addr);
    if (reg->fast_table[addr_start] == 0xff) {
        /* start 不在表内则不合法 */
        return FALSE;
    }

    /* 结束位置指向为某个数据跨多个寄存器空间的头地址则不合法，快表用来判断数据合法性 */
    uint8_t addr_end = (start + read_reg_len - 1) % reg->start_addr;
    if (reg->fast_table[addr_end] != 0xff && reg->data[reg->fast_table[addr_end]].len > 1) {
        /* 结尾指向一个合法值，但实际合法值占用两个寄存的情况不合法。 */
        return FALSE;
    }

    /* 正确定位 end 对应的指针数据的地址 */
    if (reg->fast_table[addr_end] == 0xff) {
        addr_end--;
    }

    /* 将最终数据转换为 modbus 的交换格式进行发送，任意位置读取必须使用块表否则根据字节长度无法定位尾部 */
    uint8_t pos   = 0;
    uint8_t index = 0;
//    buffer[pos++] = buffer[pos];                    // 从机地址
    pos++;
    buffer[pos++] = READ_CMD;                       // 功能码
    buffer[pos++] = read_reg_len * 2;               // 数据长度是字节数

    opt_hardware();  // 回调，需要实时操作硬件响应的数据，如 RTC 等。

    for (uint8_t i   = addr_start; i <= addr_end; i++) {
        if ((index = reg->fast_table[i]) != 0xff) {// 块表寻址
            if (reg->data[index].len == 1) {
                buffer[pos++] = ((uint8_t * )(reg->data[index].p))[1];
                buffer[pos++] = ((uint8_t * )(reg->data[index].p))[0];


            } else if (reg->data[index].len == 2) {
                buffer[pos++] = ((uint8_t * )(reg->data[index].p))[3];
                buffer[pos++] = ((uint8_t * )(reg->data[index].p))[2];
                buffer[pos++] = ((uint8_t * )(reg->data[index].p))[1];
                buffer[pos++] = ((uint8_t * )(reg->data[index].p))[0];
            } else if (reg->data[index].len == 4) {
                uint8_t      tmp_cnt = reg->data[index].len * 2;
                for (uint8_t _       = 0; _ < tmp_cnt; _++) {
                    buffer[pos++] = ((uint8_t * )(reg->data[index].p))[tmp_cnt - 1 - i];
                }
            }
        }
    }
    uint16_t     crc = check_crc16(buffer, pos);
    buffer[pos++] = (uint8_t)(crc & 0x00ff);
    buffer[pos++] = (uint8_t)(crc >> 8);
    return pos;
}

/*
上位机设置数据，写入到 mcu 中
*/
// TODO 错误返回时候的错误码
static uint8_t buff_to_data(volatile RegGroup_t *reg, uint16_t start, uint16_t len, uint8_t *buffer) {
    uint8_t  tmp_buff[4];
    uint16_t write_reg_len = buffer[5];

    /* 起始位置不在合法范围内。 */
    if (start < reg->start_addr) {
        return FALSE;
    }

    /* 寄存器长度不是字节长度的两倍 */
    if (buffer[5] * 2 != buffer[6]) {
        return FALSE;
    }

    /*  字节长度和实际接收到的数据个数不匹配。 */
    if (buffer[6] != len - 9) {
        return FALSE;
    }

    /* 数据操作的位置超出可读写寄存器范围。 */
    if (start + write_reg_len - 1 > reg->end_addr) {
        return FALSE;
    }

    /* 起始位置指向为某个数据的中间值则不合法，快表用来判断数据合法性 */
    uint8_t addr_start = (start % reg->start_addr);
    if (reg->fast_table[addr_start] == 0xff) {
        /* start 不在表内则不合法 */
        return FALSE;
    }

    /* 结束位置指向为某个数据跨多个寄存器空间的头地址则不合法，快表用来判断数据合法性 */
    uint8_t addr_end = (start + write_reg_len - 1) % reg->start_addr;
    if (reg->fast_table[addr_end] != 0xff && reg->data[reg->fast_table[addr_end]].len > 1) {
        /* 结尾指向一个合法值，但实际合法值占用两个寄存的情况不合法。 */
        return FALSE;
    }

    /* 正确定位 end 对应的指针数据的地址 */
    if (reg->fast_table[addr_end] == 0xff) {
        addr_end--;
    }

    /* 特殊数据处理策略，如：设备地址、波特率等 */
    old_modbus_addr = *(uint8_t *) g_reg[0].data[0].p;// 从机地址

    /* 将最终数据转换为 modbus 的交换格式进行发送，任意位置读取必须使用块表否则根据字节长度无法定位尾部 */
    uint8_t      pos   = 7;
    uint8_t      index = 0;
    for (uint8_t i     = addr_start; i <= addr_end; i++) {
        if ((index = reg->fast_table[i]) != 0xff) {// 块表寻址
#ifdef MODBUS_USING_RW           
            if (reg->data[index].rw != TYPE_RW) {  // 判断读写数据操作是否不合法
                return FALSE;
            }
#endif
            /* buffer 存储到相应变量中 */
            if (reg->data[index].len == 2) {
                tmp_buff[3] = buffer[pos++];
                tmp_buff[2] = buffer[pos++];
                tmp_buff[1] = buffer[pos++];
                tmp_buff[0] = buffer[pos++];

#ifdef MODBUS_USING_FORMAT                
                // BCD 码处理解析判断
                if (reg->data[index].format == FORMAT_BCD) {
                    uint32       tmp = 0;
                    for (uint8_t _   = 0; _ < 4; _++) {
                        if (((tmp_buff[_] & 0x0f) > 0x09) || (((tmp_buff[_] >> 8) & 0x0f) > 0x09)) {
                            return FALSE;
                        }
                    }
                }
#endif                
                
#ifdef MODBUS_USING_RANGE                
                // 取值范围判断
                if (reg->data[index].type == UINT32) {
                    if (reg->data[index].range.DnRange <= *((uint32 *) tmp_buff)
                        && *((uint32 *) tmp_buff) <= reg->data[index].range.UpRange) {
                        ((uint8_t * )(reg->data[index].p))[0] = tmp_buff[0];
                        ((uint8_t * )(reg->data[index].p))[1] = tmp_buff[1];
                        ((uint8_t * )(reg->data[index].p))[2] = tmp_buff[2];
                        ((uint8_t * )(reg->data[index].p))[3] = tmp_buff[3];
                    } else {
                        return FALSE;
                    }
                } else if (reg->data[index].type == REAL4) {
                    if (reg->data[index].range.DnRange <= *((real4 *) tmp_buff)
                        && *((real4 *) tmp_buff) <= reg->data[index].range.UpRange) {
                        ((uint8_t * )(reg->data[index].p))[0] = tmp_buff[0];
                        ((uint8_t * )(reg->data[index].p))[1] = tmp_buff[1];
                        ((uint8_t * )(reg->data[index].p))[2] = tmp_buff[2];
                        ((uint8_t * )(reg->data[index].p))[3] = tmp_buff[3];
                    } else {
                        return FALSE;
                    }
                } else if (reg->data[index].type == REAL8) {        // double 双精度浮点型，暂时没有经过测试验证
                    if (reg->data[index].range.DnRange <= *((real8 *) tmp_buff)
                        && *((real8 *) tmp_buff) <= reg->data[index].range.UpRange) {
                        for (uint8_t _ = 0; _ < 8; _++) {
                            ((uint8_t * )(reg->data[index].p))[_] = tmp_buff[_];
                        }
                    } else {
                        return FALSE;
                    }
                }
#else
                if (reg->data[index].type == UINT32) {
                    ((uint8_t * )(reg->data[index].p))[0] = tmp_buff[0];
                    ((uint8_t * )(reg->data[index].p))[1] = tmp_buff[1];
                    ((uint8_t * )(reg->data[index].p))[2] = tmp_buff[2];
                    ((uint8_t * )(reg->data[index].p))[3] = tmp_buff[3];

                } else if (reg->data[index].type == REAL4) {
                    ((uint8_t * )(reg->data[index].p))[0] = tmp_buff[0];
                    ((uint8_t * )(reg->data[index].p))[1] = tmp_buff[1];
                    ((uint8_t * )(reg->data[index].p))[2] = tmp_buff[2];
                    ((uint8_t * )(reg->data[index].p))[3] = tmp_buff[3];

                } else if (reg->data[index].type == REAL8) {        // double 双精度浮点型，暂时没有经过测试验证
                    for (uint8_t _ = 0; _ < 8; _++) {
                        ((uint8_t * )(reg->data[index].p))[_] = tmp_buff[_];
                    }
                }
#endif

            } else if (reg->data[index].len == 1) {
                tmp_buff[1] = buffer[pos++];
                tmp_buff[0] = buffer[pos++];

#ifdef MODBUS_USING_FORMAT                
                // BCD 码处理解析判断
                if (reg->data[index].format == FORMAT_BCD) {
                    uint16 tmp = 0;
                    if (((tmp_buff[0] & 0x0f) > 0x09) || (((tmp_buff[0] >> 4) & 0x0f) > 0x09)) {
                        return FALSE;
                    }
                    if (((tmp_buff[1] & 0x0f) > 0x09) || (((tmp_buff[1] >> 4) & 0x0f) > 0x09)) {
                        return FALSE;
                    }
                }
#endif
                
#ifdef MODBUS_USING_RANGE                
                // 取值范围判断
                if (reg->data[index].range.DnRange <= *((uint16 *) tmp_buff)
                    && *((uint16 *) tmp_buff) <= reg->data[index].range.UpRange) {
                    ((uint8_t * )(reg->data[index].p))[1] = tmp_buff[1];
                    ((uint8_t * )(reg->data[index].p))[0] = tmp_buff[0];
                } else {
                    return FALSE;
                }
#else
                ((uint8_t * )(reg->data[index].p))[1] = tmp_buff[1];
                ((uint8_t * )(reg->data[index].p))[0] = tmp_buff[0];
#endif
            }

//            /* buffer 存储到相应变量中 */
//            if (reg->data[index].len == 2) {
//                *((uint8_t * )(reg->data[index].p) + 1) = buffer[pos++];
//                *((uint8_t * )(reg->data[index].p))     = buffer[pos++];
//                *((uint8_t * )(reg->data[index].p) + 3) = buffer[pos++];
//                *((uint8_t * )(reg->data[index].p) + 2) = buffer[pos++];
//            } else {
//                *((uint8_t * )(reg->data[index].p) + 1) = buffer[pos++];
//                *((uint8_t * )(reg->data[index].p))     = buffer[pos++];
//            }
        }
    }
    pos = 0;
    buffer[pos++] = old_modbus_addr;           // 从机地址
//    buffer[pos++] = old_modbus_addr;           // 从机地址
//    buffer[pos++] = buffer[pos];           // 从机地址
    buffer[pos++] = WRITE_CMD;                 // 功能码
    buffer[pos++] = (uint8_t)(start >> 8);          // 功能码
    buffer[pos++] = (uint8_t)(start & 0xff);        // 功能码
    buffer[pos++] = (uint8_t)(write_reg_len >> 8);  // 寄存器长度高位
    buffer[pos++] = (uint8_t)(write_reg_len & 0xff);// 寄存器长度低位

    uint16_t crc = check_crc16(buffer, pos);
    buffer[pos++] = (uint8_t)(crc & 0x00ff);
    buffer[pos++] = (uint8_t)(crc >> 8);

    /* 特殊数据处理策略，如：设备地址、波特率等 */
    old_modbus_addr = *(uint8_t *) g_reg[0].data[0].p;// 从机地址

    return pos;
}

static uint8_t modbus_ack(uint8_t addr, uint8_t code, uint8_t *buffer) {
    buffer[0]    = addr;
    buffer[1]    = code;
    buffer[2]    = 0x01;
    uint16_t crc = check_crc16(buffer, 3);
    buffer[3] = (uint8_t)(crc & 0x00ff);
    buffer[4] = (uint8_t)(crc >> 8);
    return MODBUS_ERR_LEN;
}


/* 从机地址判断 */
static mcu_bool_t addr_check(uint8_t *addr) {
//    return addr == addr_modbus_addr ? TRUE : FALSE;

//    if (addr == addr_modbus_addr || addr == 0x00F7) {
    if (*addr == g_modbus_addr) {
        return TRUE;
    } else if (*addr == def_addr) {
        *addr = def_addr;
        return TRUE;
    } else {
        return FALSE;
    }
}


static uint8_t get_index(uint16_t addr) {
    for (uint8_t i = 0; i < REG_ALL_LEN; i++) {
        if (addr == modbus_addr_map[i][0]) {
            return modbus_addr_map[i][1];
        }
    }
    return 0;
}

static void test_tmp(RegGroup_t *reg, uint16_t start, uint8_t len, uint8_t *buffer) {

}

/*
    buffer ： 收发数据缓冲区，直接串口使用
    len ： 字节码长度
    send_fun_ptr ： 发送函数
    status :
            0: 读取成功
            1: 表示设置成功数据
            -1: 功能码错误
*/
MOD_STATUS_t modbus_com(uint8_t *buffer, uint8_t *len, ops_t cb) {
    uint8_t      slen   = *len;
    MOD_STATUS_t status = 0;

    uint8_t  slave_addr = buffer[0];                    /* 从机地址 */
    uint8_t  fun_code   = buffer[1];                    /* 主机发送过来的功能码 */
    uint16_t head_addr  = (buffer[2] << 8) + buffer[3]; /* 寄存器起始地址 */
    uint8_t  index      = get_index(head_addr);

    if (slave_addr == 0x00) {
        cb(fun_code);
        return MOD_WR_OK;
    }
    
    /* CRC 校验错误和地址校验出错时，不做响应 */
    if (check_crc16(buffer, slen) != 0 || !addr_check(buffer)) {
        *len = 0;
        return MOD_NO_ANS;
    }

    switch (fun_code) { /* 功能码选择功能 */
        case READ_CMD:  /* 0x03:上位机读参数/数据命令 */
            if ((*len = data_to_buff(&g_reg[index], head_addr, slen, buffer)) != 0) {
                status = MOD_RD_OK;
            } else {
                *len = modbus_ack(slave_addr, READ_ERR, buffer);
                status = MOD_RD_ERR;
            }
     
            break;
        case WRITE_CMD: /* 0x10:上位机写参数命令 */
            if ((*len = buff_to_data(&g_reg[index], head_addr, slen, buffer)) != 0) {
//                void TestWriteAllValue(void); // TEMP 临时增加，最好使用 dma 防止多次写坏
//                TestWriteAllValue();
                status = MOD_WR_OK;
            } else {
                *len = modbus_ack(slave_addr, WRITE_ERR, buffer);
                status = MOD_WR_ERR;
            }
            break;
            // TODO 补足补充其他功能码

        default:
            *len = modbus_ack(slave_addr, fun_code | 0x80, buffer);
            status = MOD_WR_ERR;
            break;
    }
    return status;
    //    send_fun_ptr(buffer, len);
}
