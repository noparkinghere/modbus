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
 * @file        modbus.h
 *
 * @brief       
 *
 * @revision
 *          Date:           2022-09-26
 *          Author:         Damon
 *          Notes:        
 *
 * @description
 *                  特别注意：  1. 要求每一个段的数据个数不超过 MAX_DATA_LEN 值。
 *                              2. 地址需要按顺序连续，地址和数组位置一一对应，不能前面是 1000 后面一组我是 A000
 ***********************************************************************************************************************
 */

#ifndef MCU_MODBUS_H
#define MCU_MODBUS_H

#include "common.h"
#include "stdint.h"


// 加入这些判断后使用空间为 6.5KB，不加入这些判断使用空间为 3.5KB
//#define MODBUS_USING_RW
//#define MODBUS_USING_FORMAT
//#define MODBUS_USING_RANGE



#define MAX_DATA_LEN  100  // 数据分段中每组数据的最长长度
#define MODBUS_ERR_LEN 5

typedef unsigned char      uint8;
typedef float              real4;
typedef double             real8;
typedef unsigned int       uint32;
typedef unsigned short int uint16;
typedef void (*ops_t)(uint8 );

typedef enum {

    READ_CMD  = 0x03,// 上位机读参数/数据命令
    WRITE_CMD = 0x10,// 上位机写参数命令
    READ_ERR  = 0x83,// 读取寄存器错误
    WRITE_ERR = 0x90,// 写寄存器错误
} ModbusFeatureType;

// 每个寄存器长度，一般是 0, 1, 2 三种
// 1 对应是 uint16_t
// 2 对应 uint32_t 和 float 类型
typedef enum {
    TYPE_NONE = 0,
    UINT16 = 1,
    UINT32 = 2,
    REAL4  = 3,
    REAL8  = 4,
} RegDataType;

typedef enum {
    LEN_NONE = 0,
    LEN_U16 = 1,
    LEN_U32 = 2,
    LEN_FLOAT = 2,
} RegDataLen;

// 读写权限配置
typedef enum {
    TYPE_R = 0,
    TYPE_RW = 1,
} RegRWType;

// 取值范围配置
typedef struct {
    float UpRange;
    float DnRange;
} RegRangeType;

// 数据解析格式
typedef enum {
    FORMAT_HEX = 0,
    FORMAT_BCD = 1,
    FORMAT_FLOAT = 2,
    FORMAT_DOUBLE = 3,
    FORMAT_STRING = 5,
} RegDataFormat;

typedef struct {
    void *     p;   // 数据变量绑定
    RegDataType type;
    RegDataLen len;
    uint16_t addr;// modbus 地址表和 fast_table 分开是为了验证地址合法性
#ifdef MODBUS_USING_RW           
    RegRWType   rw;
#endif
#ifdef MODBUS_USING_RANGE  
    RegRangeType range;
#endif

#ifdef MODBUS_USING_FORMAT                
    RegDataFormat format;
#endif

} PData;

typedef struct {
    uint16_t       fast_table[MAX_DATA_LEN];// 块表，具备唯一性，对首地址取余除二运算得游标
    volatile PData         *data;      // 准备数据
    uint16_t      valid_data_cnt; // 合法数据个数，不是寄存器个数也不是字节数
    uint16_t start_addr;     // 寄存器组起始地址
    uint16_t end_addr;       // 寄存器组结束地址
} RegGroup_t;

typedef enum{
    MOD_FUN_ERR = -2,
    OTHER_T = -1,          // 其他协议
    MOD_WR_ERR = -10,
    MOD_WR_OK = 10,
    MOD_NO_ANS = 0,
    MOD_RD_ERR = -20,
    MOD_RD_OK = 20,
} MOD_STATUS_t;

MOD_STATUS_t modbus_com(uint8_t *buffer, uint8_t *len, ops_t cb);
void init_modbus(void);
void offer_val(int *reg_num, RegGroup_t** reg_arr);

#endif //TOTALIZER_ONEOS_MODBUS_H
