# mcu 简易 modbus 库

## 介绍

单片机使用的一个具备基本功能的 modbus 协议库，当前只支持读和写两个操作，其他可以根据自己要求进行增减。

**该库在底层对 modbus 协议进行了一些额外的约束，可以进行取值判断，读写权限约束等。**

该库仅用于学习实验，一切出现的其他问题，概不负责，用户需要自行解决。

## 说明

本项目工程师的工作原理是通过 run_script 将 excel 表格中对应的 modbus 协议内容转换为 json 文件和 c 原文件。

而同时生成的 json 文件，可以作为上位机测试工具协议载入的必要文件，上位机打开后协议会自动载入，上位机不需要进行修改，每次直接更改协议即可。

### json 脚本生成

运行 run_script 会根据 excel 文件生成对应的 json 和 C 源码，run_script 会运行多个 py 脚本逐个执行。

run_script 需要根据 excel 的格式内容，对 config.ini 文件内容进行稍加修改。

```
[分组]
组数 = 7
组名位置 = 3
组名变量名 = 4
开始地址 = 16
结束地址 = 17
寄存器个数 = 18
合法值个数 = 19

[组x]
生成 = yes
起始位置行 = 8
结束位置行 = 33

```

### 下位机C协议
下位机的 C 语言协议部分 C 语言内容，存放在 ./code 文件夹下。将生成的文件复制到项目中即可。

c 原文件可以直接使用在嵌入式项目中，其中有以下几个宏定义，这些宏定义会开启响应功能，不开启这些功能的情况下，ram 使用可以减少一般，对于一些资源紧张的且使用参数角度的应用可以关闭这些定义，这些文件在 modbus_addr.c 文件的开头。

```
// define MODBUS_USING_RW
// define MODBUS_USING_FORMAT
// define MODBUS_USING_RANGE
```

./src 存放了相关源码，modbus 文件是主要 modbus 实现的代码。

./src/common 中存放了相关测试变量对应的原始定义。


### 上位机使用

modbus_addr_py 作为 pyqt5 上位机的启动文件，该文件会运行生成上位机。通过将 json 文件，上 位机识别 json 文件后自动生成图形界面和相关测试功能。



#### 安装教程

使用 release 中的 exe 文件直接打开即可，无需安装。

#### 使用说明

使用 release 中的 exe 文件直接打开即可，无需安装。


#### 参与贡献

Damon