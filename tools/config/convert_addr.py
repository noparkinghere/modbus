import json
from collections import OrderedDict

import convert2json

output_code_addr = "../../modbus.c"
output_head_addr = "../../modbus.h"


# convert2json.json_convert()

with open(".\\config\\auto_modbus.json", 'r', encoding='utf-8') as f:
# with open("auto_modbus.json", 'r', encoding='utf-8') as f:
    data = json.loads(f.read())

with open(".\\config\\other.txt", 'r', encoding='utf-8') as f:
    # with open("auto_modbus.json", 'r', encoding='utf-8') as f:
    header = f.read()


"""
头文件生成部分
"""
res = ""
res += f"""#include "common.h"   
#include <stdint.h>
#include "modbus_base.h"
{header}

#ifndef MCU_431_MODBUS_H
#define MCU_431_MODBUS_H


#define REG_ALL_LEN {data["分组数"]}
extern RegGroup_t g_reg[REG_ALL_LEN];
"""


mid1 = ""
for j, i in enumerate(data["寄存器组"]):
    data_str = ""
    group = eval(f"""data["寄存器组"][{j}]""")
    mid1 += f"""
// {group["寄存器组名称"]}
extern PData arr_data_{j}[]; """

mid2 = f"""
extern RegGroup_t g_reg[REG_ALL_LEN];"""

res += f"""


#endif //MCU_431_MODBUS_H

"""


# with open("..\\hc32l196mcta\\customized\\com\\modbus_addr.h", 'w', encoding='utf-8') as f:
#     f.write(res)

elements = (',\n    ').join([f"""{{{ele["起始地址"]}, {i}}}""" for i,ele in enumerate(data["寄存器组"])])


"""
源文件生成部分：
"""

mid0 = f"""
const uint16_t modbus_addr_map[REG_ALL_LEN][2] = {{
    {elements}
}};

volatile PData* p_arr_data[REG_ALL_LEN];
"""

mid1 = ''
for j, i in enumerate(data["寄存器组"]):
    data_str = ""
    group = eval(f"""data["寄存器组"][{j}]""")
    for _ in group["数据块"]:
        data_str += f"""{{  // {_["名称"]}
        .p = (void *)&({_["对应变量名"]}), // 对应变量名
        .type = {_["类型"]}, // 类型
        .len = {(lambda x : "LEN_FLOAT" if x == 'REAL4' else ("LEN_U16" if x=="UINT16" else ("LEN_U32" if x=="UINT32" else "LEN_NONE")))(_["类型"])}, // 长度
        .addr = {_["地址十六进制"]}, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_{_["读写权限"]}, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={{.DnRange = {_["取值下限"]}, .UpRange = {_["取值上限"]},}}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_{_["解析"]}, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    }},"""
    mid1 += f"""
// {group["寄存器组名称"]}
volatile PData arr_data_{j}[] = {{
    {data_str}
}};
"""

mid2 = ''

for _, i in enumerate(data["寄存器组"]):
    data_str = ""
    group = eval(f"""data["寄存器组"][{_}]""")
    mid2 += f"""
    {{ // {group["寄存器组名称"]}
        .valid_data_cnt = {group["合法值个数"]}, // 有效合法值个数
        .start_addr = {group["起始地址"]}, // 寄存器组起始地址
        .end_addr = {group["结束地址"]}, // 寄存器组结束地址
        .data = arr_data_{_}, // 数据指针
    }},
"""

mid2 = f"""volatile RegGroup_t g_reg[REG_ALL_LEN] = {{{mid2}}};"""

res = f"""// 自动生成 modbus 对应协议表地址
// 本文件需要完全应用

#define REG_ALL_LEN {data["分组数"]}

// define MODBUS_USING_RW
// define MODBUS_USING_FORMAT
// define MODBUS_USING_RANGE


{mid0}

{mid1}

{mid2}
"""

# res1 = res
#
# res = mid1 + res1



with open(".\\code\\modbus_addr.c", 'w', encoding='utf-8') as f:
    f.write(res)




