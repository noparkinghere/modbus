from __future__ import unicode_literals
import json
import xlrd

from configparser import ConfigParser


# for i in range(1, int(dict(cfg.items("分组"))["组数"])+1):
#     for j in dict(cfg.items(f"组{i}")):
#         print(dict(cfg.items(f"组{i}"))["起始地址"])


def json_convert():
    cfg = ConfigParser()
    cfg.read('./config.ini', "utf-8")
    file_path = str(dict(cfg.items("协议文件路径"))["路径"])
    # print(cfg.items("分组"))

    # name_col = int(dict(cfg.items("分段位置"))["名称"]) - 1
    # unit_col = int(dict(cfg.items("分段位置"))["单位"]) - 1
    # dn_range_col = int(dict(cfg.items("分段位置"))["取值下限"]) - 1
    # up_range_col = int(dict(cfg.items("分段位置"))["取值上限"]) - 1
    # var_col = int(dict(cfg.items("分段位置"))["对应变量名"]) - 1
    # type_col = int(dict(cfg.items("分段位置"))["类型"]) - 1
    # reg_col = int(dict(cfg.items("分段位置"))["寄存器数"]) - 1
    # rw_col = int(dict(cfg.items("分段位置"))["读写"]) - 1
    # reg_addr_col = int(dict(cfg.items("分段位置"))["地址十六进制"]) - 1
    # usr_group = int(dict(cfg.items("分段位置"))["用户组"]) - 1

    group_name_col = int(dict(cfg.items("分组"))["组名位置"]) - 1
    group_alias_col = int(dict(cfg.items("分组"))["组名变量名"]) - 1
    start_col = int(dict(cfg.items("分组"))["开始地址"]) - 1
    end_col = int(dict(cfg.items("分组"))["结束地址"]) - 1
    reg_cnt_col = int(dict(cfg.items("分组"))["寄存器个数"]) - 1
    valid_cnt_col = int(dict(cfg.items("分组"))["合法值个数"]) - 1

    # 注意 excel 中的行列不能用 A11 这种形式表示，这个库必须使用 row, col 的形式来表示行列，且 0 作为起始
    addr_plan = [
        {"寄存器名称": "出厂整机", "寄存器变量名": "REG_ALL", "起始地址行号": "7", "结束地址行号": "14"},  # 从 0 开始全部需要减一
        {"寄存器名称": "杂项全局配置", "寄存器变量名": "REG_MISC", "起始地址行号": "19", "结束地址行号": "39"},
    ]

    # xlsx = xlrd.open_workbook("D:\\OneDrive\\work\\2MG模块\\stm32l452版本\\2MGV452_modbus\\doc\\ttl2modbus通讯协议表.xlsx")
    # xlsx = xlrd.open_workbook(".\\ttl2modbus通讯协议表.xlsx")
    xlsx = xlrd.open_workbook(file_path)
    table = xlsx.sheet_by_index(0)
    # print(table)
    # print(table.cell_value(1, 0))
    # print(table.cell_value("A1"))   # 错误代码
    # print(table.cell(5, 1).value)
    # print(int(table.cell_value(int(addr_plan[1]["起始地址行号"]), byte_cnt_col)))
    # new_work = xlwt.Workbook()
    # worksheet = new_work.add_sheet("111")
    # worksheet.write(0, 0, 'test')
    # new_work.save("位置.xls")

    res = ''
    all = ""
    for _ in range(1, int(dict(cfg.items("分组"))["组数"]) + 1):
        s = ""
        for i in range(int(dict(cfg.items(f"组{_}"))["起始位置行"]) - 1, int(dict(cfg.items(f"组{_}"))["结束位置行"])):
            # s += f"""
            # {{"名称": "{table.cell_value(i, name_col)}",
            # "单位": "{table.cell_value(i, unit_col)}",
            # "取值下限": "{table.cell_value(i, dn_range_col)}",
            # "取值上限": "{table.cell_value(i, up_range_col)}",
            # "对应变量名": "{table.cell_value(i, var_col)}",
            # "类型": "{table.cell_value(i, type_col)}",
            # "长度": "{str(int(table.cell_value(i, reg_col)))}",
            # "读写权限": "{table.cell_value(i, rw_col)}",
            # "地址": "0x{table.cell_value(i, reg_addr_col)}",
            # "用户组": "{int(table.cell_value(i, usr_group))}",
            # }},"""
            s += "{"
            for j in cfg.items("分段位置"):
                # print(j)
                if j[0] == "寄存器数" or j[0] == "用户组":
                    s += f""""{j[0]}": "{int(table.cell_value(i, int(j[1]) - 1))}","""
                elif j[0] == "地址十六进制":
                    s += f""""{j[0]}": "0x{table.cell_value(i, int(j[1]) - 1)}","""
                elif j[0] == "取值下限" or j[0] == "取值上限":
                    # if table.cell_value(i, int(dict(cfg.items("分段位置"))["类型"])-1) == "UINT16" or table.cell_value(i,
                    #                                          int(dict(cfg.items("分段位置"))["类型"])-1) == "UINT32":
                    #     s += f""""{j[0]}": "{int(table.cell_value(i, int(j[1]) - 1))}","""
                    # else:
                    #     s += f""""{j[0]}": "{table.cell_value(i, int(j[1]) - 1)}","""
                    s += f""""{j[0]}": "{table.cell_value(i, int(j[1]) - 1)}","""
                else:
                    s += f""""{j[0]}": "{table.cell_value(i, int(j[1]) - 1)}","""
                # s += f""""{j[0]}": "{j[1]}","""
                # print(s)
            s += "},"

        row = dict(cfg.items(f"组{_}"))

        all += f"""
        {{
        "是否生成代码": "{dict(cfg.items(f"组{_}"))["生成"]}",
        "寄存器组名称": "{table.cell_value(int(row["起始位置行"]) - 3, group_name_col)}",
        "寄存器组变量名": "{table.cell_value(int(row["起始位置行"]) - 3, group_alias_col)}",
        "起始地址": "0x{table.cell_value(int(row["起始位置行"]) - 1, start_col)}",
        "结束地址": "0x{table.cell_value(int(row["起始位置行"]) - 1, end_col)}",
        "寄存器个数": "{str(int(table.cell_value(int(row["起始位置行"]) - 1, reg_cnt_col)))}",
        "合法值个数": "{str(int(table.cell_value(int(row["起始位置行"]) - 1, valid_cnt_col)))}",
        "数据块": [{s}],
        }},"""

    print("*" * 20)

    # for _ in addr_plan:
    #     s = ""
    #     for i in range(int(_["起始地址行号"]), int(_["结束地址行号"]) + 1):
    #         s += f"""
    #         {{"名称": "{table.cell_value(i, name_col)}",
    #         "单位": "{table.cell_value(i, unit_col)}",
    #         "取值下限": "{table.cell_value(i, dn_range_col)}",
    #         "取值上限": "{table.cell_value(i, up_range_col)}",
    #         "对应变量名": "{table.cell_value(i, var_col)}",
    #         "类型": "{table.cell_value(i, type_col)}",
    #         "长度": "{str(int(table.cell_value(i, reg_cnt_col)))}",
    #         "读写权限": "{table.cell_value(i, rw_col)}",
    #         "地址": "0x{table.cell_value(i, reg_addr_col)}",
    #         "用户组": "{int(table.cell_value(i, usr_group))}",
    #         }},"""
    #
    #     all += f"""
    #     {{
    #     "寄存器组名称": "{table.cell_value(int(_["起始地址行号"]) - 2, group_name_col)}",
    #     "寄存器组变量名": "{table.cell_value(int(_["起始地址行号"]) - 2, group_alias_col)}",
    #     "起始地址": "0x{table.cell_value(int(_["起始地址行号"]), start_col)}",
    #     "结束地址": "0x{table.cell_value(int(_["起始地址行号"]), end_col)}",
    #     "寄存器个数": "{str(int(table.cell_value(int(_["起始地址行号"]), reg_cnt_col)))}",
    #     "合法值个数": "{str(int(table.cell_value(int(_["起始地址行号"]), valid_cnt_col)))}",
    #     "数据块": [{s}],
    #     }},"""

    res = f"""{{
    "status": 1,
    "分组数":{int(dict(cfg.items("分组"))["组数"])},
    "自动读取组":\"{str(dict(cfg.items("自动读取段"))["组号"])}\",
    "寄存器组": [{all}
    ],
    "Author": "Frank",
    "message": "OK"
}}"""

    # print(dict(cfg.items("自动读取段"))["组号"])

    with open(".\\config\\auto_modbus.json", 'w', encoding='utf-8') as f:
        f.write(json.dumps(eval(res), ensure_ascii=False))


    print("conver2json.py succeed!")

if __name__ == '__main__':
    json_convert()
