#include <os_util.h>
#include <stdint.h>
#include <os_version.h>
#include "oneos_config.h"
#include "board.h"
#include <shell.h>
#include <string.h>
#include <os_stddef.h>
#include <timer/clocksource.h>
#include <timer/clockevent.h>
#include <os_memory.h>
#include <os_mq.h>
#include "lcd_disp.h"
#include <common.h>


os_task_t *lpuart_task_ptr = OS_NULL;
os_task_t *uart_task_ptr = OS_NULL;
os_task_t *checkmem_task_ptr = OS_NULL;
os_task_t *alarm_task_ptr = OS_NULL;
os_task_t *eeprom_task_ptr = OS_NULL;
os_task_t *timesync_task_ptr = OS_NULL;
os_task_t *onenet_task_ptr = OS_NULL;
os_task_t *fota_task_ptr = OS_NULL;

os_sem_t *sem_dynamic;
os_mq_t *alarm_dynamic;
os_mq_t *eeprom_dynamic;
os_timer_t timer_s1;



/*******************************************************************
 * ͨ��������ܷ���
 */
// �����ʱ n ΢��
void soft_delay_nus(mcu_uint32_t time) {
    for (mcu_uint32_t i = 0; i < time; i++) {
        __NOP();
    }
}



// ������ر���
os_device_t *os_lpuart0;
os_device_t *os_uart0;


/****************************************************************
 * ����ר�ñ���
 */
volatile mcu_uint8_t g_utest8;
volatile mcu_uint16_t g_utest16;
volatile mcu_uint32_t g_utest32;

volatile mcu_int8_t g_itest8;
volatile mcu_int16_t g_itest16;
volatile mcu_int32_t g_itest32;

volatile float   g_ftest;
volatile double g_dftest;

/****************************************************************
 * TODO ��ʱ����ȫ����Ҫʹ�ú�ͨѶ�ı���
 * ���������õ���ȫ�ֱ���
 */

/**
 * ��������
 */
volatile mcu_uint16_t g_modbus_addr;
volatile mcu_int8_t   g_t_id[18];
volatile mcu_int8_t   g_t_hard_v[10];
volatile mcu_int8_t   g_t_soft_v[16];
volatile mcu_uint16_t g_t_manu_id;
volatile model_t      g_t_model = DEFAULT_MODLE_INFO;
volatile mcu_int32_t  g_t_date;


/**
 * ���ÿ���
 */
volatile t_config_t g_t_ctrl = CTRL_CRD_MAP_INFO;
//t_config_t g_t_status;
volatile t_config_t g_t_status = CTRL_CRD_MAP_INFO;

/**
 * misc ����
 */
// g_t_model �������Ѿ�����

// �ۻ��� TODO ���������� double ����
volatile float g_t_total_p;      // �����ۻ���
volatile float g_t_total_n;

// ����ʱ�� 0-23
volatile mcu_uint16_t g_t_freeze_time;

// ������ָ��ģ���Ĭ�Ϲ���ģʽ
volatile mcu_uint16_t g_t_m_def_state;


volatile float g_t_std_temp;
volatile float g_t_std_press;

// �ϴ�ʱ�䣺ÿ��̶�ʱ�䣨0~23���㣩��Ĭ����00�㣩
//volatile mcu_uint16_t g_t_up_time2=33;
//volatile mcu_uint16_t g_t_up_time3=134;
//volatile mcu_uint16_t g_t_up_time4=235;
//volatile mcu_uint16_t g_t_up_time5=536;
//volatile mcu_uint16_t g_t_up_time6=637;
volatile mcu_uint16_t g_t_tcp_port;          // �˿ں�
//volatile mcu_uint16_t g_t_up_time1 = 1;         // TODO ֻҪ����ֵ�ͻᱨջ���󣬲鿴�˱����ļ��ͷ�ɢ�ļ�ʵ���޷���λԭ��
volatile mcu_uint16_t g_t_up_time = 1;         // TODO ֻҪ����ֵ�ͻᱨջ���󣬲鿴�˱����ļ��ͷ�ɢ�ļ�ʵ���޷���λԭ��

// ��������������IP
volatile ip_t g_net_addr;

/**
 * ��������
 */
volatile fix_points_t g_t_amend;

volatile module_bus_base_t g_m_bus_base;
volatile module_bus_diag_t g_m_bus_diag;
volatile para1_data_t      g_m_para1;
volatile fix_points_t      g_m_para2;        // ������ȡ 2








void display_total_qusm(float qn, float total)
{
    char ch[16] = {0};

    sprintf(ch, "%.3f", qn);
    lcd_disp_qusm_val(ch, OS_TRUE);
    sprintf(ch, "%.4f", total);
    lcd_disp_totle_val(ch, OS_TRUE);
}

