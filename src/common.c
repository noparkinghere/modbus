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
 * 通用软件功能方法
 */
// 软件延时 n 微秒
void soft_delay_nus(mcu_uint32_t time) {
    for (mcu_uint32_t i = 0; i < time; i++) {
        __NOP();
    }
}



// 驱动相关变量
os_device_t *os_lpuart0;
os_device_t *os_uart0;


/****************************************************************
 * 测试专用变量
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
 * TODO 临时定义全局需要使用和通讯的变量
 * 定义所有用到的全局变量
 */

/**
 * 出厂整机
 */
volatile mcu_uint16_t g_modbus_addr;
volatile mcu_int8_t   g_t_id[18];
volatile mcu_int8_t   g_t_hard_v[10];
volatile mcu_int8_t   g_t_soft_v[16];
volatile mcu_uint16_t g_t_manu_id;
volatile model_t      g_t_model = DEFAULT_MODLE_INFO;
volatile mcu_int32_t  g_t_date;


/**
 * 配置开关
 */
volatile t_config_t g_t_ctrl = CTRL_CRD_MAP_INFO;
//t_config_t g_t_status;
volatile t_config_t g_t_status = CTRL_CRD_MAP_INFO;

/**
 * misc 参数
 */
// g_t_model 在上面已经定义

// 累积量 TODO 后续考虑用 double 类型
volatile float g_t_total_p;      // 正向累积量
volatile float g_t_total_n;

// 冻结时间 0-23
volatile mcu_uint16_t g_t_freeze_time;

// 积算仪指定模块的默认工作模式
volatile mcu_uint16_t g_t_m_def_state;


volatile float g_t_std_temp;
volatile float g_t_std_press;

// 上传时间：每天固定时间（0~23整点）（默认是00点）
//volatile mcu_uint16_t g_t_up_time2=33;
//volatile mcu_uint16_t g_t_up_time3=134;
//volatile mcu_uint16_t g_t_up_time4=235;
//volatile mcu_uint16_t g_t_up_time5=536;
//volatile mcu_uint16_t g_t_up_time6=637;
volatile mcu_uint16_t g_t_tcp_port;          // 端口号
//volatile mcu_uint16_t g_t_up_time1 = 1;         // TODO 只要不赋值就会报栈错误，查看了编译文件和分散文件实在无法定位原因。
volatile mcu_uint16_t g_t_up_time = 1;         // TODO 只要不赋值就会报栈错误，查看了编译文件和分散文件实在无法定位原因。

// 服务器域名或者IP
volatile ip_t g_net_addr;

/**
 * 修正参数
 */
volatile fix_points_t g_t_amend;

volatile module_bus_base_t g_m_bus_base;
volatile module_bus_diag_t g_m_bus_diag;
volatile para1_data_t      g_m_para1;
volatile fix_points_t      g_m_para2;        // 参数读取 2








void display_total_qusm(float qn, float total)
{
    char ch[16] = {0};

    sprintf(ch, "%.3f", qn);
    lcd_disp_qusm_val(ch, OS_TRUE);
    sprintf(ch, "%.4f", total);
    lcd_disp_totle_val(ch, OS_TRUE);
}

