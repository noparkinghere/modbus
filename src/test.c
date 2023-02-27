
void modbus_data_parsing(void * arg) {
    os_uint8_t status;
    os_uint8_t len;
    volatile int cnt = 1;
    os_uint8_t *p_buff = modbus_frame.buff;
    init_modbus();
    while (1) {
        modbus_frame.len = modbus_uart_get_string(p_buff);       
        status = modbus_com(modbus_frame.buff, &(modbus_frame.len), arg);
//        os_task_msleep(1000);
        if (modbus_frame.len != 0) {
            os_device_write_nonblock(os_uart0, 0, modbus_frame.buff, modbus_frame.len);
//            if (status == MOD_WR_OK) {
////                    TestWriteAllValue();        // TEMP 临时增加，最好使用 dma 防止多次写坏
//            }
        }
    }
}




void modbus_serial_task(void *parameter) {
    parameter = parameter;
    os_uint32_t rx_cnt = 0;
    os_uint8_t i;
    sem_dynamic_uart = os_sem_create("sem_dynamic_uart", 0, OS_SEM_MAX_VALUE);
    OS_ASSERT_EX(OS_NULL != sem_dynamic_uart, "sem create err!\r\n");

    sem_send = os_sem_create("sem_dynamic_uart", 0, OS_SEM_MAX_VALUE);
    OS_ASSERT_EX(OS_NULL != sem_send, "sem create err!\r\n");
    
    os_uart0 = modbus_uart0_init();

    os_task_t *thread;              /* 任务控制块 */
    thread = os_task_create("modbus_data_parsing", (void (*)(void *))modbus_data_parsing,
                            parameter, 512, 9);
    os_task_set_time_slice(thread, 5);

    OS_ASSERT(thread);
    os_task_startup(thread);                        /* 任务开始 */
}




void test(void) {
    // TODO 设置参数的协议，临时选举你用 modbus 协议，后续会更改。
    os_task_t *para_task;
    para_task = os_task_create("para_task", modbus_serial_task, console_dbg, 512, 2);
    OS_ASSERT(para_task);
    os_task_startup(para_task);
    
}
