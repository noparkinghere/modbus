/**
 ***********************************************************************************************************************
 * Copyright (C) 2023, Chinaweise Co.,Ltd All rights reserved.
 *
 * This software is owned and published by:
 * Chinaweise Co.,Ltd(WS).
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 * Disclaimer:
 * WS MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * WS SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 * @file        console_dbg.c
 *
 * @revision
 *          Date:           2023-02-21
 *          Author:         Frank
 *          Notes:          
 *                          其他附加协议，兼容串口内容，可以使用这个文件进行
 *                          console_dbg 中对应的帧格式是 00 xx ,xx 为功能码，
 *                          xx 对应的功能吗调用相对应的函数，实现相关功能即可。
 * @description
 *          
 *          
 ***********************************************************************************************************************
 */


#include "console_dbg.h"
#include <os_memory.h>
#include <os_util.h>
#include "common.h"

static void memshow_task(void *parameter) {
    os_meminfo_t info;
    static os_int32_t cnt = 0;

    while (1) {
        os_memory_info(&info);
        os_kprintf("\r\n");
        os_kprintf("memory details %dth:\r\n", cnt++);
        os_kprintf("memory total    : %d\r\n", info.mem_total);
        os_kprintf("memory used     : %d\r\n", info.mem_used);
        os_kprintf("memory max used : %d\r\n", info.mem_maxused);
        os_task_msleep(5000);
    }
}

static void show_mem(void) {
    os_meminfo_t info;
    static os_int32_t cnt = 0;

    os_memory_info(&info);
    os_kprintf("\r\n");
    os_kprintf("memory details %dth:\r\n", cnt++);
    os_kprintf("memory total    : %d\r\n", info.mem_total);
    os_kprintf("memory used     : %d\r\n", info.mem_used);
    os_kprintf("memory max used : %d\r\n", info.mem_maxused);

}


#ifdef OS_USING_CONSOLE
void console_dbg(os_uint8_t cmd) {
    switch (cmd) {
        case 0x01:
            // 临时周期性打印任务，可能存在异常，无需使用
            checkmem_task_ptr = os_task_create("alarm", memshow_task, NULL, 512, 5);
            OS_ASSERT(checkmem_task_ptr);
            os_task_startup(checkmem_task_ptr);
        case 0x81:      // 存在异常，无需使用
            if (checkmem_task_ptr != OS_NULL) {
                os_task_destroy(checkmem_task_ptr);
            }
        case 0x10:      // 主要使用的方法，单次调用函数，不会造成异常。
            show_mem();
    }
}

#else
void console_dbg(os_uint8_t cmd) {
    return;
}
#endif