// 自动生成 modbus 对应协议表地址
// 本文件需要完全应用

#define REG_ALL_LEN 7

// define MODBUS_USING_RW
// define MODBUS_USING_FORMAT
// define MODBUS_USING_RANGE



const uint16_t modbus_addr_map[REG_ALL_LEN][2] = {
    {0xD0, 0},
    {0x1000, 1},
    {0x2000, 2},
    {0x3000, 3},
    {0xA000, 4},
    {0xA100, 5},
    {0xA200, 6}
};

volatile PData* p_arr_data[REG_ALL_LEN];



// 积算仪出厂整机
volatile PData arr_data_0[] = {
    {  // 设备地址
        .p = (void *)&(g_modbus_addr), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD0, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 1.0, .UpRange = 247.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号1
        .p = (void *)&(g_t_id[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD1, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号2
        .p = (void *)&(g_t_id[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD2, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号3
        .p = (void *)&(g_t_id[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD3, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号4
        .p = (void *)&(g_t_id[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD4, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号5
        .p = (void *)&(g_t_id[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD5, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号6
        .p = (void *)&(g_t_id[10]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD6, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号7
        .p = (void *)&(g_t_id[12]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD7, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号8
        .p = (void *)&(g_t_id[14]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD8, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号9
        .p = (void *)&(g_t_id[16]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xD9, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号1
        .p = (void *)&(g_t_hard_v[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xDA, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号2
        .p = (void *)&(g_t_hard_v[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xDB, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号3
        .p = (void *)&(g_t_hard_v[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xDC, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号4
        .p = (void *)&(g_t_hard_v[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xDD, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号5
        .p = (void *)&(g_t_hard_v[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xDE, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本1
        .p = (void *)&(g_t_soft_v[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xDF, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本2
        .p = (void *)&(g_t_soft_v[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE0, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本3
        .p = (void *)&(g_t_soft_v[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE1, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本4
        .p = (void *)&(g_t_soft_v[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE2, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本5
        .p = (void *)&(g_t_soft_v[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE3, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本6
        .p = (void *)&(g_t_soft_v[10]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE4, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本7
        .p = (void *)&(g_t_soft_v[12]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE5, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本8
        .p = (void *)&(g_t_soft_v[14]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE6, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 制造商ID
        .p = (void *)&(g_t_manu_id), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE7, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 1.0, .UpRange = 0x9999,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_BCD, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 设备类型
        .p = (void *)&(g_t_model.model), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xE8, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 1.0, .UpRange = 9.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 出厂日期
        .p = (void *)&(g_t_date), // 对应变量名
        .type = UINT32, // 类型
        .len = LEN_U32, // 长度
        .addr = 0xE9, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0x20210101, .UpRange = 0x21000101,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_BCD, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};

// 积算仪配置参数
volatile PData arr_data_1[] = {
    {  // 存储数据使能
        .p = (void *)&(g_t_ctrl.save), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1000, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 存储数据状态
        .p = (void *)&(g_t_status.save), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1001, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断数据使能
        .p = (void *)&(g_t_ctrl.diag_data), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1002, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断数据状态
        .p = (void *)&(g_t_status.diag_data), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1003, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 开关阀使能
        .p = (void *)&(g_t_ctrl.valve), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1004, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 开关阀状态
        .p = (void *)&(g_t_status.valve), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1005, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 误差修正使能
        .p = (void *)&(g_t_ctrl.err), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1006, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 误差修正状态
        .p = (void *)&(g_t_status.err), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1007, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 物联网上传使能
        .p = (void *)&(g_t_ctrl.net_up), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1008, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 物联网上传状态
        .p = (void *)&(g_t_status.net_up), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1009, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器或者域名使能
        .p = (void *)&(g_t_ctrl.net), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x100A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器或者域名状态
        .p = (void *)&(g_t_status.net), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x100B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 蓝牙使能
        .p = (void *)&(g_t_ctrl.ble), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x100C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 蓝牙状态
        .p = (void *)&(g_t_status.ble), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x100D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 声时模块接收使能
        .p = (void *)&(g_t_ctrl.module_rev), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x100E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 声时模块接收状态
        .p = (void *)&(g_t_status.module_rev), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x100F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 声时模块命令使能
        .p = (void *)&(g_t_ctrl.module_cmd), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1010, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 声时模块命令状态
        .p = (void *)&(g_t_status.module_cmd), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1011, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 设置声时模块数据1使能
        .p = (void *)&(g_t_ctrl.module_set1), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1012, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 设置声时模块数据1状态
        .p = (void *)&(g_t_status.module_set1), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1013, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 设置声时模块数据2使能
        .p = (void *)&(g_t_ctrl.module_set2), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1014, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 设置声时模块数据2状态
        .p = (void *)&(g_t_status.module_set2), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1015, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 终端console使能
        .p = (void *)&(g_t_ctrl.console), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1016, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 终端console状态
        .p = (void *)&(g_t_status.console), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1017, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 红外数据通讯使能
        .p = (void *)&(g_t_ctrl.infrared), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1018, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 红外数据通讯状态
        .p = (void *)&(g_t_status.infrared), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1019, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 防拆外壳被打开开启使能
        .p = (void *)&(g_t_ctrl.tamper), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x101A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 防拆外壳被打开开启状态
        .p = (void *)&(g_t_status.tamper), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x101B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 标定使能
        .p = (void *)&(g_t_ctrl.calib), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x101C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 标定状态
        .p = (void *)&(g_t_status.calib), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x101D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 积算仪电量过低使能
        .p = (void *)&(g_t_ctrl.t_low_p), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x101E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 积算仪电量过低状态
        .p = (void *)&(g_t_status.t_low_p), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x101F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 模块电量过低使能
        .p = (void *)&(g_t_ctrl.m_low_p), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1020, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 模块电量过低状态
        .p = (void *)&(g_t_status.m_low_p), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x1021, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 1.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};

// 积算仪其他参数
volatile PData arr_data_2[] = {
    {  // 设备类型
        .p = (void *)&(g_t_model.model), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2000, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 1.0, .UpRange = 9.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 最小流量
        .p = (void *)&(g_t_model.qmin), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x2001, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.001, .UpRange = 10.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 最大流量
        .p = (void *)&(g_t_model.qmax), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x2003, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 100.0, .UpRange = 10000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 始动流量
        .p = (void *)&(g_t_model.threshold), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x2005, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.1, .UpRange = 10.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 脉冲当量
        .p = (void *)&(g_t_model.p4flow), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x2007, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 正向累积量
        .p = (void *)&(g_t_total_p), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x2009, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.001, .UpRange = 10000000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 反向累积量
        .p = (void *)&(g_t_total_n), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x200B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.001, .UpRange = 10000000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 正常冻结间隔
        .p = (void *)&(g_t_freeze_time), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x200D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 积算仪指定模块的默认工作模式
        .p = (void *)&(g_t_m_def_state), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x200E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = , .UpRange = ,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 标况温度
        .p = (void *)&(g_t_std_temp), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x200F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -50.0, .UpRange = 60.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 标况压力
        .p = (void *)&(g_t_std_press), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x2011, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 30.0, .UpRange = 200.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 上传时间
        .p = (void *)&(g_t_up_time), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2013, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 23.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名1
        .p = (void *)&(g_net_addr.domain[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2014, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名2
        .p = (void *)&(g_net_addr.domain[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2015, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名3
        .p = (void *)&(g_net_addr.domain[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2016, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名4
        .p = (void *)&(g_net_addr.domain[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2017, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名5
        .p = (void *)&(g_net_addr.domain[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2018, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名6
        .p = (void *)&(g_net_addr.domain[10]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2019, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名7
        .p = (void *)&(g_net_addr.domain[12]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x201A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名8
        .p = (void *)&(g_net_addr.domain[14]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x201B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名9
        .p = (void *)&(g_net_addr.domain[16]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x201C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 服务器域名10
        .p = (void *)&(g_net_addr.domain[18]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x201D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP1
        .p = (void *)&(g_net_addr.ip[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x201E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP2
        .p = (void *)&(g_net_addr.ip[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x201F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP3
        .p = (void *)&(g_net_addr.ip[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2020, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP4
        .p = (void *)&(g_net_addr.ip[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2021, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP5
        .p = (void *)&(g_net_addr.ip[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2022, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP6
        .p = (void *)&(g_net_addr.ip[10]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2023, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP7
        .p = (void *)&(g_net_addr.ip[12]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2024, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // IP8
        .p = (void *)&(g_net_addr.ip[14]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2025, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 端口号
        .p = (void *)&(g_t_tcp_port), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x2026, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 1000.0, .UpRange = 65535.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};

// 积算仪误差修正
volatile PData arr_data_3[] = {
    {  // 工况瞬时量修正点数
        .p = (void *)&(g_t_amend.points_num), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0x3000, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 10.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值1
        .p = (void *)&(g_t_amend.point[0].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3001, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值1
        .p = (void *)&(g_t_amend.point[0].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3003, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值2
        .p = (void *)&(g_t_amend.point[1].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3005, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值2
        .p = (void *)&(g_t_amend.point[1].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3007, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值3
        .p = (void *)&(g_t_amend.point[2].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3009, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值3
        .p = (void *)&(g_t_amend.point[2].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x300B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值4
        .p = (void *)&(g_t_amend.point[3].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x300D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值4
        .p = (void *)&(g_t_amend.point[3].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x300F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值5
        .p = (void *)&(g_t_amend.point[4].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3011, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值5
        .p = (void *)&(g_t_amend.point[4].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3013, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值6
        .p = (void *)&(g_t_amend.point[5].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3015, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值6
        .p = (void *)&(g_t_amend.point[5].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3017, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值7
        .p = (void *)&(g_t_amend.point[6].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3019, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值7
        .p = (void *)&(g_t_amend.point[6].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x301B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值8
        .p = (void *)&(g_t_amend.point[7].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x301D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值8
        .p = (void *)&(g_t_amend.point[7].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x301F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值9
        .p = (void *)&(g_t_amend.point[8].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3021, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值9
        .p = (void *)&(g_t_amend.point[8].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3023, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值10
        .p = (void *)&(g_t_amend.point[9].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3025, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值10
        .p = (void *)&(g_t_amend.point[9].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3027, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值11
        .p = (void *)&(g_t_amend.point[10].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x3029, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值11
        .p = (void *)&(g_t_amend.point[10].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x302B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量平均值12
        .p = (void *)&(g_t_amend.point[11].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x302D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值12
        .p = (void *)&(g_t_amend.point[11].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0x302F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};

// 声时模块数据
volatile PData arr_data_4[] = {
    {  // 瞬时流量
        .p = (void *)&(g_m_bus_base.qusm), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA000, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 30000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 正向声时
        .p = (void *)&(g_m_bus_base.tup), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA002, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 50.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 逆向声时
        .p = (void *)&(g_m_bus_base.tdn), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA004, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 50.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 温度
        .p = (void *)&(g_m_bus_base.temp), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA006, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -35.0, .UpRange = 60.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 压力
        .p = (void *)&(g_m_bus_base.press), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA008, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 60.0, .UpRange = 1000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 增益1
        .p = (void *)&(g_m_bus_base.gain1), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA00A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 255.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 增益2
        .p = (void *)&(g_m_bus_base.gain2), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA00B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 255.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断瞬时流量
        .p = (void *)&(g_m_bus_diag.qusm), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA00C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 30000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断正向声时1
        .p = (void *)&(g_m_bus_diag.tup1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA00E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 50.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断逆向声时1
        .p = (void *)&(g_m_bus_diag.tdn1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA010, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 50.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断正向声时2
        .p = (void *)&(g_m_bus_diag.tup2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA012, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 50.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断逆向声时2
        .p = (void *)&(g_m_bus_diag.tdn2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA014, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 50.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断声速1
        .p = (void *)&(g_m_bus_diag.vos1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA016, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 200.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断温度
        .p = (void *)&(g_m_bus_diag.temp), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA018, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -35.0, .UpRange = 60.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断压力
        .p = (void *)&(g_m_bus_diag.press), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA01A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 60.0, .UpRange = 1000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断增益1
        .p = (void *)&(g_m_bus_diag.gain1), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA01C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 255.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断增益2
        .p = (void *)&(g_m_bus_diag.gain2), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA01D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 255.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Rup1
        .p = (void *)&(g_m_bus_diag.rup1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA01E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 2.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Rdown1
        .p = (void *)&(g_m_bus_diag.rdn1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA020, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 2.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Rup2
        .p = (void *)&(g_m_bus_diag.rup2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA022, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 2.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Rdown2
        .p = (void *)&(g_m_bus_diag.rdn2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA024, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 2.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Err1
        .p = (void *)&(g_m_bus_diag.err1), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA026, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 256.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Err2
        .p = (void *)&(g_m_bus_diag.err2), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA027, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 256.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断Sys
        .p = (void *)&(g_m_bus_diag.sys), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA028, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 256.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断测量次数
        .p = (void *)&(g_m_bus_diag.meas_cnt), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA029, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 1.0, .UpRange = 64.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断DW1
        .p = (void *)&(g_m_bus_diag.dw1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA02A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 2.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断DW2
        .p = (void *)&(g_m_bus_diag.dw2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA02C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.01, .UpRange = 2.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 诊断声速2
        .p = (void *)&(g_m_bus_diag.vos2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA02E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 200.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};

// 声时模块参数1
volatile PData arr_data_5[] = {
    {  // 表体编号1
        .p = (void *)&(g_m_para1.id[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA100, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号2
        .p = (void *)&(g_m_para1.id[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA101, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号3
        .p = (void *)&(g_m_para1.id[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA102, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号4
        .p = (void *)&(g_m_para1.id[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA103, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号5
        .p = (void *)&(g_m_para1.id[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA104, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号6
        .p = (void *)&(g_m_para1.id[10]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA105, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 表体编号7
        .p = (void *)&(g_m_para1.id[12]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA106, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号1
        .p = (void *)&(g_m_para1.hard_v[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA107, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号2
        .p = (void *)&(g_m_para1.hard_v[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA108, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号3
        .p = (void *)&(g_m_para1.hard_v[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA109, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号4
        .p = (void *)&(g_m_para1.hard_v[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA10A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 硬件版本号5
        .p = (void *)&(g_m_para1.hard_v[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA10B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本1
        .p = (void *)&(g_m_para1.soft_v[0]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA10C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本2
        .p = (void *)&(g_m_para1.soft_v[2]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA10D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本3
        .p = (void *)&(g_m_para1.soft_v[4]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA10E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本4
        .p = (void *)&(g_m_para1.soft_v[6]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA10F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本5
        .p = (void *)&(g_m_para1.soft_v[8]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA110, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本6
        .p = (void *)&(g_m_para1.soft_v[10]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA111, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本7
        .p = (void *)&(g_m_para1.soft_v[12]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA112, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 软件版本8
        .p = (void *)&(g_m_para1.soft_v[14]), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA113, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 32.0, .UpRange = 122.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_STRING, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 理论声程1
        .p = (void *)&(g_m_para1.t_len1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA114, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 10.0, .UpRange = 10000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 理论声程2
        .p = (void *)&(g_m_para1.t_len2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA116, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 10.0, .UpRange = 10000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 实际声程1
        .p = (void *)&(g_m_para1.r_len1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA118, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 10.0, .UpRange = 10000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 实际声程2
        .p = (void *)&(g_m_para1.r_len2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA11A, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 10.0, .UpRange = 10000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 增益1
        .p = (void *)&(g_m_para1.gain1), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA11C, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 255.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 增益2
        .p = (void *)&(g_m_para1.gain2), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA11D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 255.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 声速1
        .p = (void *)&(g_m_para1.vos1), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA11E, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 200.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 声速2
        .p = (void *)&(g_m_para1.vos2), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA120, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_R, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 200.0, .UpRange = 500.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};

// 声时模块参数2
volatile PData arr_data_6[] = {
    {  // 工况瞬时量修正点数
        .p = (void *)&(g_m_para2.points_num), // 对应变量名
        .type = UINT16, // 类型
        .len = LEN_U16, // 长度
        .addr = 0xA200, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = 0.0, .UpRange = 10.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_HEX, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点1
        .p = (void *)&(g_m_para2.point[0].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA201, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值1
        .p = (void *)&(g_m_para2.point[0].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA203, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点2
        .p = (void *)&(g_m_para2.point[1].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA205, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值2
        .p = (void *)&(g_m_para2.point[1].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA207, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点3
        .p = (void *)&(g_m_para2.point[2].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA209, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值3
        .p = (void *)&(g_m_para2.point[2].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA20B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点4
        .p = (void *)&(g_m_para2.point[3].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA20D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值4
        .p = (void *)&(g_m_para2.point[3].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA20F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点5
        .p = (void *)&(g_m_para2.point[4].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA211, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值5
        .p = (void *)&(g_m_para2.point[4].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA213, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点6
        .p = (void *)&(g_m_para2.point[5].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA215, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值6
        .p = (void *)&(g_m_para2.point[5].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA217, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点7
        .p = (void *)&(g_m_para2.point[6].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA219, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值7
        .p = (void *)&(g_m_para2.point[6].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA21B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点8
        .p = (void *)&(g_m_para2.point[7].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA21D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值8
        .p = (void *)&(g_m_para2.point[7].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA21F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点9
        .p = (void *)&(g_m_para2.point[8].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA221, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值9
        .p = (void *)&(g_m_para2.point[8].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA223, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点10
        .p = (void *)&(g_m_para2.point[9].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA225, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100000.0, .UpRange = 100000.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值10
        .p = (void *)&(g_m_para2.point[9].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA227, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点11
        .p = (void *)&(g_m_para2.point[10].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA229, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值11
        .p = (void *)&(g_m_para2.point[10].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA22B, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量修正点12
        .p = (void *)&(g_m_para2.point[11].val), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA22D, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },{  // 工况瞬时量误差值12
        .p = (void *)&(g_m_para2.point[11].err), // 对应变量名
        .type = REAL4, // 类型
        .len = LEN_FLOAT, // 长度
        .addr = 0xA22F, // 地址
#ifdef MODBUS_USING_RW           
        .rw = TYPE_RW, // 读写权限
#endif
#ifdef MODBUS_USING_RANGE   
        .range ={.DnRange = -100.0, .UpRange = 100.0,}, // 取值范围
#endif
#ifdef MODBUS_USING_FORMAT                
        .format = FORMAT_FLOAT, // 转换格式：0-BCD，1-HEX， 2-FLOAT
#endif
    },
};


volatile RegGroup_t g_reg[REG_ALL_LEN] = {
    { // 积算仪出厂整机
        .valid_data_cnt = 26, // 有效合法值个数
        .start_addr = 0xD0, // 寄存器组起始地址
        .end_addr = 0xEA, // 寄存器组结束地址
        .data = arr_data_0, // 数据指针
    },

    { // 积算仪配置参数
        .valid_data_cnt = 34, // 有效合法值个数
        .start_addr = 0x1000, // 寄存器组起始地址
        .end_addr = 0x1021, // 寄存器组结束地址
        .data = arr_data_1, // 数据指针
    },

    { // 积算仪其他参数
        .valid_data_cnt = 31, // 有效合法值个数
        .start_addr = 0x2000, // 寄存器组起始地址
        .end_addr = 0x2026, // 寄存器组结束地址
        .data = arr_data_2, // 数据指针
    },

    { // 积算仪误差修正
        .valid_data_cnt = 25, // 有效合法值个数
        .start_addr = 0x3000, // 寄存器组起始地址
        .end_addr = 0x3030, // 寄存器组结束地址
        .data = arr_data_3, // 数据指针
    },

    { // 声时模块数据
        .valid_data_cnt = 28, // 有效合法值个数
        .start_addr = 0xA000, // 寄存器组起始地址
        .end_addr = 0xA02F, // 寄存器组结束地址
        .data = arr_data_4, // 数据指针
    },

    { // 声时模块参数1
        .valid_data_cnt = 28, // 有效合法值个数
        .start_addr = 0xA100, // 寄存器组起始地址
        .end_addr = 0xA121, // 寄存器组结束地址
        .data = arr_data_5, // 数据指针
    },

    { // 声时模块参数2
        .valid_data_cnt = 25, // 有效合法值个数
        .start_addr = 0xA200, // 寄存器组起始地址
        .end_addr = 0xA230, // 寄存器组结束地址
        .data = arr_data_6, // 数据指针
    },
};
