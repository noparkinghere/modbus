
#include "common.h"    
#include "test4modbus.h"
#include "modbus_base.h"

void test_modbus() {
addr_modbus_addr      = 0x0001;  /* 通讯地址 */

// 积算仪出厂整机
g_modbus_addr = 247.0; // 设备地址
g_t_id[0] = 122.0; // 表体编号1
g_t_id[2] = 122.0; // 表体编号2
g_t_id[4] = 122.0; // 表体编号3
g_t_id[6] = 122.0; // 表体编号4
g_t_id[8] = 122.0; // 表体编号5
g_t_id[10] = 122.0; // 表体编号6
g_t_id[12] = 122.0; // 表体编号7
g_t_id[14] = 122.0; // 表体编号8
g_t_id[16] = 122.0; // 表体编号9
g_t_hard_v[0] = 122.0; // 硬件版本号1
g_t_hard_v[2] = 122.0; // 硬件版本号2
g_t_hard_v[4] = 122.0; // 硬件版本号3
g_t_hard_v[6] = 122.0; // 硬件版本号4
g_t_hard_v[8] = 122.0; // 硬件版本号5
g_t_soft_v[0] = 122.0; // 软件版本1
g_t_soft_v[2] = 122.0; // 软件版本2
g_t_soft_v[4] = 122.0; // 软件版本3
g_t_soft_v[6] = 122.0; // 软件版本4
g_t_soft_v[8] = 122.0; // 软件版本5
g_t_soft_v[10] = 122.0; // 软件版本6
g_t_soft_v[12] = 122.0; // 软件版本7
g_t_soft_v[14] = 122.0; // 软件版本8
g_t_manu_id = 0x9999; // 制造商ID
g_t_model.model = 9.0; // 设备类型
g_t_date = 0x21000101; // 出厂日期
 


// 积算仪配置参数
g_t_ctrl.save = 1.0; // 存储数据使能
g_t_status.save = 1.0; // 存储数据状态
g_t_ctrl.diag_data = 1.0; // 诊断数据使能
g_t_status.diag_data = 1.0; // 诊断数据状态
g_t_ctrl.valve = 1.0; // 开关阀使能
g_t_status.valve = 1.0; // 开关阀状态
g_t_ctrl.err = 1.0; // 误差修正使能
g_t_status.err = 1.0; // 误差修正状态
g_t_ctrl.net_up = 1.0; // 物联网上传使能
g_t_status.net_up = 1.0; // 物联网上传状态
g_t_ctrl.net = 1.0; // 服务器或者域名使能
g_t_status.net = 1.0; // 服务器或者域名状态
g_t_ctrl.ble = 1.0; // 蓝牙使能
g_t_status.ble = 1.0; // 蓝牙状态
g_t_ctrl.module_rev = 1.0; // 声时模块接收使能
g_t_status.module_rev = 1.0; // 声时模块接收状态
g_t_ctrl.module_cmd = 1.0; // 声时模块命令使能
g_t_status.module_cmd = 1.0; // 声时模块命令状态
g_t_ctrl.module_set1 = 1.0; // 设置声时模块数据1使能
g_t_status.module_set1 = 1.0; // 设置声时模块数据1状态
g_t_ctrl.module_set2 = 1.0; // 设置声时模块数据2使能
g_t_status.module_set2 = 1.0; // 设置声时模块数据2状态
g_t_ctrl.console = 1.0; // 终端console使能
g_t_status.console = 1.0; // 终端console状态
g_t_ctrl.infrared = 1.0; // 红外数据通讯使能
g_t_status.infrared = 1.0; // 红外数据通讯状态
g_t_ctrl.tamper = 1.0; // 防拆外壳被打开开启使能
g_t_status.tamper = 1.0; // 防拆外壳被打开开启状态
g_t_ctrl.calib = 1.0; // 标定使能
g_t_status.calib = 1.0; // 标定状态
g_t_ctrl.t_low_p = 1.0; // 积算仪电量过低使能
g_t_status.t_low_p = 1.0; // 积算仪电量过低状态
g_t_ctrl.m_low_p = 1.0; // 模块电量过低使能
g_t_status.m_low_p = 1.0; // 模块电量过低状态
 


// 积算仪其他参数
g_t_model.model = 9.0; // 设备类型
g_t_model.qmin = 10.0; // 最小流量
g_t_model.qmax = 10000.0; // 最大流量
g_t_model.threshold = 10.0; // 始动流量
g_t_model.p4flow = 100.0; // 脉冲当量
g_t_total_p = 10000000.0; // 正向累积量
g_t_total_n = 10000000.0; // 反向累积量
g_t_freeze_time = 100.0; // 正常冻结间隔
g_t_m_def_state = ; // 积算仪指定模块的默认工作模式
g_t_std_temp = 60.0; // 标况温度
g_t_std_press = 200.0; // 标况压力
g_t_up_time = 23.0; // 上传时间
g_net_addr.domain[0] = 122.0; // 服务器域名1
g_net_addr.domain[2] = 122.0; // 服务器域名2
g_net_addr.domain[4] = 122.0; // 服务器域名3
g_net_addr.domain[6] = 122.0; // 服务器域名4
g_net_addr.domain[8] = 122.0; // 服务器域名5
g_net_addr.domain[10] = 122.0; // 服务器域名6
g_net_addr.domain[12] = 122.0; // 服务器域名7
g_net_addr.domain[14] = 122.0; // 服务器域名8
g_net_addr.domain[16] = 122.0; // 服务器域名9
g_net_addr.domain[18] = 122.0; // 服务器域名10
g_net_addr.ip[0] = 122.0; // IP1
g_net_addr.ip[2] = 122.0; // IP2
g_net_addr.ip[4] = 122.0; // IP3
g_net_addr.ip[6] = 122.0; // IP4
g_net_addr.ip[8] = 122.0; // IP5
g_net_addr.ip[10] = 122.0; // IP6
g_net_addr.ip[12] = 122.0; // IP7
g_net_addr.ip[14] = 122.0; // IP8
g_t_tcp_port = 65535.0; // 端口号
 


// 积算仪误差修正
g_t_amend.points_num = 10.0; // 工况瞬时量修正点数
g_t_amend.point[0].val = 100000.0; // 工况瞬时量平均值1
g_t_amend.point[0].err = 100.0; // 工况瞬时量误差值1
g_t_amend.point[1].val = 100000.0; // 工况瞬时量平均值2
g_t_amend.point[1].err = 100.0; // 工况瞬时量误差值2
g_t_amend.point[2].val = 100000.0; // 工况瞬时量平均值3
g_t_amend.point[2].err = 100.0; // 工况瞬时量误差值3
g_t_amend.point[3].val = 100000.0; // 工况瞬时量平均值4
g_t_amend.point[3].err = 100.0; // 工况瞬时量误差值4
g_t_amend.point[4].val = 100000.0; // 工况瞬时量平均值5
g_t_amend.point[4].err = 100.0; // 工况瞬时量误差值5
g_t_amend.point[5].val = 100000.0; // 工况瞬时量平均值6
g_t_amend.point[5].err = 100.0; // 工况瞬时量误差值6
g_t_amend.point[6].val = 100000.0; // 工况瞬时量平均值7
g_t_amend.point[6].err = 100.0; // 工况瞬时量误差值7
g_t_amend.point[7].val = 100000.0; // 工况瞬时量平均值8
g_t_amend.point[7].err = 100.0; // 工况瞬时量误差值8
g_t_amend.point[8].val = 100000.0; // 工况瞬时量平均值9
g_t_amend.point[8].err = 100.0; // 工况瞬时量误差值9
g_t_amend.point[9].val = 100000.0; // 工况瞬时量平均值10
g_t_amend.point[9].err = 100.0; // 工况瞬时量误差值10
g_t_amend.point[10].val = 100000.0; // 工况瞬时量平均值11
g_t_amend.point[10].err = 100.0; // 工况瞬时量误差值11
g_t_amend.point[11].val = 100000.0; // 工况瞬时量平均值12
g_t_amend.point[11].err = 100.0; // 工况瞬时量误差值12
 


// 声时模块数据
g_m_bus_base.qusm = 30000.0; // 瞬时流量
g_m_bus_base.tup = 500.0; // 正向声时
g_m_bus_base.tdn = 500.0; // 逆向声时
g_m_bus_base.temp = 60.0; // 温度
g_m_bus_base.press = 1000.0; // 压力
g_m_bus_base.gain1 = 255.0; // 增益1
g_m_bus_base.gain2 = 255.0; // 增益2
g_m_bus_diag.qusm = 30000.0; // 诊断瞬时流量
g_m_bus_diag.tup1 = 500.0; // 诊断正向声时1
g_m_bus_diag.tdn1 = 500.0; // 诊断逆向声时1
g_m_bus_diag.tup2 = 500.0; // 诊断正向声时2
g_m_bus_diag.tdn2 = 500.0; // 诊断逆向声时2
g_m_bus_diag.vos1 = 500.0; // 诊断声速1
g_m_bus_diag.temp = 60.0; // 诊断温度
g_m_bus_diag.press = 1000.0; // 诊断压力
g_m_bus_diag.gain1 = 255.0; // 诊断增益1
g_m_bus_diag.gain2 = 255.0; // 诊断增益2
g_m_bus_diag.rup1 = 2.0; // 诊断Rup1
g_m_bus_diag.rdn1 = 2.0; // 诊断Rdown1
g_m_bus_diag.rup2 = 2.0; // 诊断Rup2
g_m_bus_diag.rdn2 = 2.0; // 诊断Rdown2
g_m_bus_diag.err1 = 256.0; // 诊断Err1
g_m_bus_diag.err2 = 256.0; // 诊断Err2
g_m_bus_diag.sys = 256.0; // 诊断Sys
g_m_bus_diag.meas_cnt = 64.0; // 诊断测量次数
g_m_bus_diag.dw1 = 2.0; // 诊断DW1
g_m_bus_diag.dw2 = 2.0; // 诊断DW2
g_m_bus_diag.vos2 = 500.0; // 诊断声速2
 


// 声时模块参数1
g_m_para1.id[0] = 122.0; // 表体编号1
g_m_para1.id[2] = 122.0; // 表体编号2
g_m_para1.id[4] = 122.0; // 表体编号3
g_m_para1.id[6] = 122.0; // 表体编号4
g_m_para1.id[8] = 122.0; // 表体编号5
g_m_para1.id[10] = 122.0; // 表体编号6
g_m_para1.id[12] = 122.0; // 表体编号7
g_m_para1.hard_v[0] = 122.0; // 硬件版本号1
g_m_para1.hard_v[2] = 122.0; // 硬件版本号2
g_m_para1.hard_v[4] = 122.0; // 硬件版本号3
g_m_para1.hard_v[6] = 122.0; // 硬件版本号4
g_m_para1.hard_v[8] = 122.0; // 硬件版本号5
g_m_para1.soft_v[0] = 122.0; // 软件版本1
g_m_para1.soft_v[2] = 122.0; // 软件版本2
g_m_para1.soft_v[4] = 122.0; // 软件版本3
g_m_para1.soft_v[6] = 122.0; // 软件版本4
g_m_para1.soft_v[8] = 122.0; // 软件版本5
g_m_para1.soft_v[10] = 122.0; // 软件版本6
g_m_para1.soft_v[12] = 122.0; // 软件版本7
g_m_para1.soft_v[14] = 122.0; // 软件版本8
g_m_para1.t_len1 = 10000.0; // 理论声程1
g_m_para1.t_len2 = 10000.0; // 理论声程2
g_m_para1.r_len1 = 10000.0; // 实际声程1
g_m_para1.r_len2 = 10000.0; // 实际声程2
g_m_para1.gain1 = 255.0; // 增益1
g_m_para1.gain2 = 255.0; // 增益2
g_m_para1.vos1 = 500.0; // 声速1
g_m_para1.vos2 = 500.0; // 声速2
 


// 声时模块参数2
g_m_para2.points_num = 10.0; // 工况瞬时量修正点数
g_m_para2.point[0].val = 100000.0; // 工况瞬时量修正点1
g_m_para2.point[0].err = 100.0; // 工况瞬时量误差值1
g_m_para2.point[1].val = 100000.0; // 工况瞬时量修正点2
g_m_para2.point[1].err = 100.0; // 工况瞬时量误差值2
g_m_para2.point[2].val = 100000.0; // 工况瞬时量修正点3
g_m_para2.point[2].err = 100.0; // 工况瞬时量误差值3
g_m_para2.point[3].val = 100000.0; // 工况瞬时量修正点4
g_m_para2.point[3].err = 100.0; // 工况瞬时量误差值4
g_m_para2.point[4].val = 100000.0; // 工况瞬时量修正点5
g_m_para2.point[4].err = 100.0; // 工况瞬时量误差值5
g_m_para2.point[5].val = 100000.0; // 工况瞬时量修正点6
g_m_para2.point[5].err = 100.0; // 工况瞬时量误差值6
g_m_para2.point[6].val = 100000.0; // 工况瞬时量修正点7
g_m_para2.point[6].err = 100.0; // 工况瞬时量误差值7
g_m_para2.point[7].val = 100000.0; // 工况瞬时量修正点8
g_m_para2.point[7].err = 100.0; // 工况瞬时量误差值8
g_m_para2.point[8].val = 100000.0; // 工况瞬时量修正点9
g_m_para2.point[8].err = 100.0; // 工况瞬时量误差值9
g_m_para2.point[9].val = 100000.0; // 工况瞬时量修正点10
g_m_para2.point[9].err = 100.0; // 工况瞬时量误差值10
g_m_para2.point[10].val = 100.0; // 工况瞬时量修正点11
g_m_para2.point[10].err = 100.0; // 工况瞬时量误差值11
g_m_para2.point[11].val = 100.0; // 工况瞬时量修正点12
g_m_para2.point[11].err = 100.0; // 工况瞬时量误差值12
 



}


