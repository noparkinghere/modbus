import json
from collections import OrderedDict

import convert2json

output_test_addr = "../../test4modbus.c"

# convert2json.json_convert()

with open(".\\config\\auto_modbus.json", 'r', encoding='utf-8') as f:
    data = json.loads(f.read())


# 生成测试头文件
res = ''
for i, _ in enumerate(data["寄存器组"]):
    data_str = ""
    group = eval(f"""data["寄存器组"][{i}]""")
    for _ in group["数据块"]:
        data_str += f"""extern {_["类型"].lower()} {_["对应变量名"]}; // {_["名称"]}
"""
    res += f"""

// {group["寄存器组名称"]}
{data_str} 

"""

res = """
#include <stdint.h>
#include "common.h"      
#include "modbus_base.h"


#ifndef MCU_431_MODBUS_TEST_H
#define MCU_431_MODBUS_TEST_H

"""    + res + """

extern uint16 addr_modbus_addr; /* 通讯地址 */

#endif // MCU_431_MODBUS_TEST_H

"""

# with open("..\\test4modbus.h", 'w', encoding='utf-8') as f:
#     f.write(res)


# 生成测试变量
mid1 = ''
mid2 = ''
for i,_ in enumerate(data["寄存器组"]):
    data_str1 = ""
    data_str2 = ""
    group = eval(f"""data["寄存器组"][{i}]""")
    for _ in group["数据块"]:
        data_str1 += f"""{_["类型"].lower()} {_["对应变量名"]} = {_["取值上限"]}; // {_["名称"]}
"""
        data_str2 += f"""{_["对应变量名"]} = {_["取值上限"]}; // {_["名称"]}
"""
    mid1 += f"""
// {group["寄存器组名称"]}
{data_str1} 

"""

    mid2 += f"""
// {group["寄存器组名称"]}
{data_str2} 

"""

res1 = f"""
#include "common.h"    
#include "test4modbus.h"
#include "modbus_base.h"

void test_modbus() {{
addr_modbus_addr      = 0x0001;  /* 通讯地址 */
{mid2}

}}


"""

with open(".\\code\\test4modbus.c", 'w', encoding='utf-8') as f:
    f.write(res1)


res2 = f"""

uint16 addr_modbus_addr      = 0x0001;  /* 通讯地址 */
{mid1}

"""

with open(".\\config\\tmp.txt", 'w', encoding='utf-8') as f:
    f.write(res)
