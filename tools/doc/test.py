from configparser import ConfigParser

cfg = ConfigParser()
cfg.read('./config.ini', "utf-8")

print(cfg.items("分段位置"))

name_col = int(dict(cfg.items("分段位置"))["名称"]) - 1
unit_col = int(dict(cfg.items("分段位置"))["单位"]) - 1
dn_range_col = int(dict(cfg.items("分段位置"))["取值下限"]) - 1
up_range_col = int(dict(cfg.items("分段位置"))["取值上限"]) - 1
var_col = int(dict(cfg.items("分段位置"))["对应变量名"]) - 1
type_col = int(dict(cfg.items("分段位置"))["类型"]) - 1
reg_cnt_col = int(dict(cfg.items("分段位置"))["寄存器数"]) - 1
rw_col = int(dict(cfg.items("分段位置"))["读写"]) - 1
reg_addr_col = int(dict(cfg.items("分段位置"))["地址十进制"]) - 1
usr_group = int(dict(cfg.items("分段位置"))["用户组"]) - 1

group_name_col = int(dict(cfg.items("分组"))["组名位置"]) - 1
group_alias_col = int(dict(cfg.items("分组"))["组名变量名"]) - 1
start_col = int(dict(cfg.items("分组"))["开始地址"]) - 1
end_col = int(dict(cfg.items("分组"))["结束地址"]) - 1
reg_cnt_col = int(dict(cfg.items("分组"))["寄存器个数"]) - 1
valid_cnt_col = int(dict(cfg.items("分组"))["合法值个数"]) - 1

print(cfg.items("分组"))