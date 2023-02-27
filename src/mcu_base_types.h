/**
 ***********************************************************************************************************************
 * Copyright (C) 2022, Chinaweise Co.,Ltd All rights reserved.
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
 * @file        mcu_base_type.h
 *
 * @revision
 *          Date:           2022-09-14
 *          Author:         Frank
 *          Notes:          
 * @description
 *          公用基础定义，方便 mcu 移植。
 *          
 ***********************************************************************************************************************
 */

#ifndef ONEOS_ECOSYS_2X_WEISE_TOTALIZER_T2_BASE_TYPE_H
#define ONEOS_ECOSYS_2X_WEISE_TOTALIZER_T2_BASE_TYPE_H


/* Alignment size for CPU architecture storage access */
//#define MCU_ALIGN_SIZE                   sizeof(mcu_base_t)

/* Basic storage type definitions */
typedef signed char        mcu_int8_t;              /* 8bit integer type */
typedef signed short       mcu_int16_t;             /* 16bit integer type */
typedef signed int         mcu_int32_t;             /* 32bit integer type */
typedef signed long long   mcu_int64_t;             /* 64bit integer type */
typedef unsigned char      mcu_uint8_t;             /* 8bit unsigned integer type */
typedef unsigned short     mcu_uint16_t;            /* 16bit unsigned integer type */
typedef unsigned int       mcu_uint32_t;            /* 32bit unsigned integer type */
typedef unsigned long long mcu_uint64_t;            /* 64bit unsigned integer type */
typedef unsigned char      mcu_bool_t;              /* Boolean type */

/* Represent Nbit CPU */
typedef signed long   mcu_base_t;              /* Nbit CPU related date type */
typedef unsigned long mcu_ubase_t;             /* Nbit unsigned CPU related storage type */

/* Else storage type definitions */
typedef mcu_int32_t mcu_err_t;               /* Type for error number */
typedef mcu_ubase_t mcu_tick_t;              /* Type for tick count */
typedef mcu_ubase_t mcu_size_t;              /* Type for size */
typedef mcu_base_t  mcu_off_t;               /* Type for offset */


/* Maximum value of base type */
#define MCU_UINT8_MAX                   0xffU                   /* Maxium value of UINT8 */
#define MCU_UINT16_MAX                  0xffffU                 /* Maxium value of UINT16 */
#define MCU_UINT32_MAX                  0xffffffffU             /* Maxium value of UINT32 */
#define MCU_UINT64_MAX                  0xffffffffffffffffULL   /* Maxium value of UINT64 */
#define MCU_INLINE                      static __inline


#define NULL                            0
#define NULL_PTR                        0

#if !defined(FALSE)
#define FALSE                           0
#endif
#if !defined(TRUE)
#define TRUE                            1
#endif
#define ENABLE                          1
#define DISABLE                         0


typedef enum {
    STATUS_ON  = 1,
    STATUS_OFF  = 0,
    STATUS_OK  = 10,
    STATUS_ERR = -1,
}                   status_t;


#define ITEM_NUM(items) sizeof(items) / sizeof(items[0])


#endif //ONEOS_ECOSYS_2X_WEISE_TOTALIZER_T2_BASE_TYPE_H
