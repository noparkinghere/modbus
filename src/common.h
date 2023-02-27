#ifndef __COMMON_H__
#define __COMMON_H__


#include "mcu_base_types.h"

#include <os_task.h>
#include <os_sem.h>
#include <os_mq.h>
#include <os_timer.h>
#include "board.h"
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



extern os_task_t *lpuart_task_ptr;
extern os_task_t *uart_task_ptr;
extern os_task_t *checkmem_task_ptr;
extern os_task_t *alarm_task_ptr;
extern os_task_t *eeprom_task_ptr;
extern os_task_t *onenet_task_ptr;
extern os_task_t *fota_task_ptr;
extern os_task_t *timesync_task_ptr;
extern os_sem_t *sem_dynamic;
extern os_mq_t *alarm_dynamic;
extern os_mq_t *eeprom_dynamic;
extern os_timer_t timer_s1;


#define COM_BUFF_SIZE 150

typedef struct {
    uint8_t buff[COM_BUFF_SIZE]; /* 串口数据缓存 */
    uint8_t len;                    /* 数据长度 */
    uint8_t pointer;                /* 串口数据实时指针 */
    //bool rev_flag;                      /* 接收到数据标记 */
    mcu_bool_t frame_finished; /* 一帧数据接收完成 */
}        com_frame_t;

void soft_delay_nus(mcu_uint32_t time);

typedef void (*fn_task_t)(void *);

/****************************************************************
 * 测试专用变量
 */
extern volatile mcu_uint8_t  g_utest8;
extern volatile mcu_uint16_t g_utest16;
extern volatile mcu_uint32_t g_utest32;

extern volatile mcu_int8_t  g_itest8;
extern volatile mcu_int16_t g_itest16;
extern volatile mcu_int32_t g_itest32;

extern volatile float  g_ftest;
extern volatile double g_dftest;


// 驱动相关变量
extern os_device_t *os_lpuart0;
extern os_device_t *os_uart0;


/****************************************************************
 * TODO 临时定义全局需要使用和通讯的变量
 * 定义所有用到的全局变量
 */



// 积算仪型号：G1.6、G2.5、G4、G6、G10、G16、G25、G40、G65
typedef enum {
    G1_6 = 1,
    G2_5 = 2,
    G4   = 3,
    G6   = 4,
    G10  = 5,
    G16  = 6,
    G25  = 7,
    G40  = 8,
    G65  = 9,
}                  enum_model;

typedef struct {
    enum_model model;
    float      qmin;
    float      qmax;
    float      threshold;    // 始动流量
    float      p4flow;       // 脉冲当量
}                  model_t;


#pragma pack(2)
typedef struct {
#define  MACROS_CFG(a) mcu_uint16_t a;
    CONFIG_TABLE
#undef  MACROS_CFG
}                  t_config_t;
#pragma pack()

//typedef struct {
//    mcu_uint16_t save;                                   // 存储数据
//    mcu_uint16_t diag_data;                              // 诊断数据
//    mcu_uint16_t valve;                                  // 开关阀
//    mcu_uint16_t err;                                    // 误差修正
//    mcu_uint16_t net_up;                                 // 物联网上传
//    mcu_uint16_t net;                                    // 服务器或者域名
//    mcu_uint16_t ble;                                    // 蓝牙
//    mcu_uint16_t module_rev;                             // 声时模块接收
//    mcu_uint16_t module_cmd;                             // 声时模块接收
//    mcu_uint16_t module_set1;                            // 设置声时模块数据1
//    mcu_uint16_t module_set2;                            // 设置声时模块数据2
//    mcu_uint16_t console;                                // 终端 console
//    mcu_uint16_t infrared;                               // 红外数据通讯
//    mcu_uint16_t tamper;                                 // 防拆外壳被打开开启
//    mcu_uint16_t calib;                                  // 标定
//    mcu_uint16_t a_low_p;                                // 积算仪电量过低
//    mcu_uint16_t m_low_p;                                // 模块电量过低
//} t_config_t;



// 正常冻结间隔1分钟、5分钟、10分钟、30分钟、60分钟；（默认60分钟）
typedef enum {
    min_1  = 1,
    min_5  = 5,
    min_10 = 10,
    min_30 = 30,
    min_60 = 60,
}                  enum_freeze;

typedef union {
    struct {
        mcu_int8_t _resv[4];
        mcu_int8_t ip[16];
    };
    mcu_int8_t domain[20];
}                  ip_t;

typedef struct {
    float val;    // 流量值
    float err;    // 误差百分比
    float border; // 误差修正的边界 x 值
}                  fix_p_t;

#define POINT_MAX_NUM             12        // 该值不能轻易修改，否则可能有影响协议内容

typedef struct {
    mcu_uint16_t points_num;
    fix_p_t      point[POINT_MAX_NUM];
}                  fix_points_t;

extern volatile float g_t_total_p;
extern volatile float g_t_total_n;


/**************************************************
 * 模组相关声明
 */
/*********************************************
 * 模块相关地址
 */

// 基础数据
typedef struct {
    float        qusm;      // 单位是 L/h
    float        tup;
    float        tdn;
    float        temp;
    float        press;
    mcu_uint16_t gain1;
    mcu_uint16_t gain2;
}                  module_bus_base_t;


// 以下诊断数据中使用，后续带有时间戳
typedef struct {
    float        qusm;
    float        tup1;
    float        tdn1;
    float        tup2;
    float        tdn2;
    float        vos1;
    float        temp;
    float        press;
    mcu_uint16_t gain1;
    mcu_uint16_t gain2;
    float        rup1;
    float        rdn1;
    float        rup2;
    float        rdn2;
    mcu_uint16_t err1;
    mcu_uint16_t err2;
    mcu_uint16_t sys;
    mcu_uint16_t meas_cnt;
    float        dw1;
    float        dw2;
    float        vos2;
}                  module_bus_diag_t;


// 参数读取 1
typedef struct {
    mcu_int8_t   id[14];
    mcu_int8_t   hard_v[10];
    mcu_int8_t   soft_v[16];
    float        t_len1;
    float        t_len2;
    float        r_len1;
    float        r_len2;
    mcu_uint16_t gain1;
    mcu_uint16_t gain2;
    float        vos1;
    float        vos2;
    // 预留
}                  para1_data_t;


/*************************************************************
 * 全局变量声明
 */


extern volatile mcu_uint16_t g_modbus_addr;
extern volatile mcu_int8_t   g_t_id[18];
extern volatile mcu_int8_t   g_t_hard_v[10];
extern volatile mcu_int8_t   g_t_soft_v[16];
extern volatile mcu_uint16_t g_t_manu_id;
extern volatile model_t      g_t_model;
extern volatile mcu_int32_t  g_t_date;


/**
 * 配置开关
 */


extern volatile t_config_t g_t_ctrl;
extern volatile t_config_t g_t_status;

/**
 * misc 参数
 */
// g_t_model 在上面已经定义

// 冻结时间 0-23
extern volatile mcu_uint16_t g_t_freeze_time;
extern volatile mcu_uint16_t g_t_m_def_state;


extern volatile float g_t_std_temp;
extern volatile float g_t_std_press;

// 上传时间：每天固定时间（0~23整点）（默认是00点）
extern volatile mcu_uint16_t g_t_tcp_port;          // 端口号
extern volatile mcu_uint16_t g_t_up_time;


/**
 * 修正参数
 */

// 服务器域名或者IP
extern volatile ip_t g_net_addr;

extern volatile fix_points_t g_t_amend;


/*********************************************
 * 模块相关地址
 */
extern volatile module_bus_base_t g_m_bus_base;
extern volatile module_bus_diag_t g_m_bus_diag;
extern volatile para1_data_t      g_m_para1;
extern volatile fix_points_t      g_m_para2;        // 参数读取 2


void display_total_qusm(float qn, float total);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __COMMON_H__ */





