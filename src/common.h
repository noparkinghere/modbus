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
    uint8_t buff[COM_BUFF_SIZE]; /* �������ݻ��� */
    uint8_t len;                    /* ���ݳ��� */
    uint8_t pointer;                /* ��������ʵʱָ�� */
    //bool rev_flag;                      /* ���յ����ݱ�� */
    mcu_bool_t frame_finished; /* һ֡���ݽ������ */
}        com_frame_t;

void soft_delay_nus(mcu_uint32_t time);

typedef void (*fn_task_t)(void *);

/****************************************************************
 * ����ר�ñ���
 */
extern volatile mcu_uint8_t  g_utest8;
extern volatile mcu_uint16_t g_utest16;
extern volatile mcu_uint32_t g_utest32;

extern volatile mcu_int8_t  g_itest8;
extern volatile mcu_int16_t g_itest16;
extern volatile mcu_int32_t g_itest32;

extern volatile float  g_ftest;
extern volatile double g_dftest;


// ������ر���
extern os_device_t *os_lpuart0;
extern os_device_t *os_uart0;


/****************************************************************
 * TODO ��ʱ����ȫ����Ҫʹ�ú�ͨѶ�ı���
 * ���������õ���ȫ�ֱ���
 */



// �������ͺţ�G1.6��G2.5��G4��G6��G10��G16��G25��G40��G65
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
    float      threshold;    // ʼ������
    float      p4flow;       // ���嵱��
}                  model_t;


#pragma pack(2)
typedef struct {
#define  MACROS_CFG(a) mcu_uint16_t a;
    CONFIG_TABLE
#undef  MACROS_CFG
}                  t_config_t;
#pragma pack()

//typedef struct {
//    mcu_uint16_t save;                                   // �洢����
//    mcu_uint16_t diag_data;                              // �������
//    mcu_uint16_t valve;                                  // ���ط�
//    mcu_uint16_t err;                                    // �������
//    mcu_uint16_t net_up;                                 // �������ϴ�
//    mcu_uint16_t net;                                    // ��������������
//    mcu_uint16_t ble;                                    // ����
//    mcu_uint16_t module_rev;                             // ��ʱģ�����
//    mcu_uint16_t module_cmd;                             // ��ʱģ�����
//    mcu_uint16_t module_set1;                            // ������ʱģ������1
//    mcu_uint16_t module_set2;                            // ������ʱģ������2
//    mcu_uint16_t console;                                // �ն� console
//    mcu_uint16_t infrared;                               // ��������ͨѶ
//    mcu_uint16_t tamper;                                 // ������Ǳ��򿪿���
//    mcu_uint16_t calib;                                  // �궨
//    mcu_uint16_t a_low_p;                                // �����ǵ�������
//    mcu_uint16_t m_low_p;                                // ģ���������
//} t_config_t;



// ����������1���ӡ�5���ӡ�10���ӡ�30���ӡ�60���ӣ���Ĭ��60���ӣ�
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
    float val;    // ����ֵ
    float err;    // ���ٷֱ�
    float border; // ��������ı߽� x ֵ
}                  fix_p_t;

#define POINT_MAX_NUM             12        // ��ֵ���������޸ģ����������Ӱ��Э������

typedef struct {
    mcu_uint16_t points_num;
    fix_p_t      point[POINT_MAX_NUM];
}                  fix_points_t;

extern volatile float g_t_total_p;
extern volatile float g_t_total_n;


/**************************************************
 * ģ���������
 */
/*********************************************
 * ģ����ص�ַ
 */

// ��������
typedef struct {
    float        qusm;      // ��λ�� L/h
    float        tup;
    float        tdn;
    float        temp;
    float        press;
    mcu_uint16_t gain1;
    mcu_uint16_t gain2;
}                  module_bus_base_t;


// �������������ʹ�ã���������ʱ���
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


// ������ȡ 1
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
    // Ԥ��
}                  para1_data_t;


/*************************************************************
 * ȫ�ֱ�������
 */


extern volatile mcu_uint16_t g_modbus_addr;
extern volatile mcu_int8_t   g_t_id[18];
extern volatile mcu_int8_t   g_t_hard_v[10];
extern volatile mcu_int8_t   g_t_soft_v[16];
extern volatile mcu_uint16_t g_t_manu_id;
extern volatile model_t      g_t_model;
extern volatile mcu_int32_t  g_t_date;


/**
 * ���ÿ���
 */


extern volatile t_config_t g_t_ctrl;
extern volatile t_config_t g_t_status;

/**
 * misc ����
 */
// g_t_model �������Ѿ�����

// ����ʱ�� 0-23
extern volatile mcu_uint16_t g_t_freeze_time;
extern volatile mcu_uint16_t g_t_m_def_state;


extern volatile float g_t_std_temp;
extern volatile float g_t_std_press;

// �ϴ�ʱ�䣺ÿ��̶�ʱ�䣨0~23���㣩��Ĭ����00�㣩
extern volatile mcu_uint16_t g_t_tcp_port;          // �˿ں�
extern volatile mcu_uint16_t g_t_up_time;


/**
 * ��������
 */

// ��������������IP
extern volatile ip_t g_net_addr;

extern volatile fix_points_t g_t_amend;


/*********************************************
 * ģ����ص�ַ
 */
extern volatile module_bus_base_t g_m_bus_base;
extern volatile module_bus_diag_t g_m_bus_diag;
extern volatile para1_data_t      g_m_para1;
extern volatile fix_points_t      g_m_para2;        // ������ȡ 2


void display_total_qusm(float qn, float total);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __COMMON_H__ */





