<h2 align="center">
🚌客运购票系统
</h2><br>
<pre align="center">
 Build with 📷<a href="https://disnox.top">disnox</a> 
</pre>

<p align="center">
<br>
<a href="https://www.disnox.top/project">🖥 More Items</a>
<br>
<a href=" " rel="nofollow"><img src="https://img.shields.io/badge/-%F0%9F%92%BBLinux-blue"></a>
<a href=" " rel="nofollow"><img src="https://img.shields.io/badge/-%F0%9F%91%A8%E2%80%8D%F0%9F%92%BBC%2FC%2B%2B-blue"></a>
<a href=" " rel="nofollow"><img src="https://img.shields.io/badge/-%F0%9F%93%9Aproject-blue"></a>
</p>


## 1. 项目简介

设计实现一个客运购票管理系统，包含用户系统和管理员系统两大板块。使用到的文件信息包括车次信息、购票信息、用户信息。均采用模拟实现。

### 1.1 管理员系统

+ 登录权限设置
  + 用户名：admin
  + 密码：123456
+ 车次信息管理
  + 车次信息的增、删、改、查
  + 按条件查询信息
  + 按条件排序信息
+ 用户信息管理
  + 用户信息的增、删、改、查

### 1.2 用户系统

+ 登录权限设置
  + 用户名：电话或者身份证号登录
  + 密码：匹配用户信息索引到密码
+ 用户操作
  + 可按条件查询客运信息
  + 可按条件排序客运信息
  + 查看本人购票信息
  + 购票、退票、充值、提现操作

## 2. 软件环境

+ **VsCode** 代码编辑器
+ **Ubuntu18.04 Linux** 子系统
+ **VMware Workstation Pro** 虚拟机
+ **MobaXterm_Personal_20.3** 或者 **SecureCRT** SSH 软件

## 3. 项目使用

在终端文件下使用命令

```C
xx@xx:xxx/project$ make
xx@xx:xxx/project$ ./output/main
// 后续步骤按选项执行就行
// 注：make clean 可清除掉可执行文件和.o文件
// 管理员系统
// 用户名：admin  密码：123456
// 用户系统
// 用户名: 15265179610  密码：1001
```

## 4. 知识点使用

+ **Linux 内核链表**：将数据域和指针域分开，将车次信息、购票信息、用户信息挂载到 Linux 内核链表上。
+ **标准IO函数使用**：使用 函数 **fopen、fgets、fscanf、fprintf、fclose** 打开信息文件读取信息、输入信息并关闭文件。
+ **函数指针**：使用函数指针创建回调函数，通过访问该函数的地址来使用各种查询、修改回调函数。
+ **内存空间**：使用 **malloc** 函数分配堆内存空间存放车次信息、购票信息、用户信息数据。
+ **结构体**：创建用户信息、购票信息、车次信息结构体类型，用于存放各种数据类型的数据。
+ **typedef**：给结构体数据类型取别名，更加方便定义。
+ **extern**：在 .h文件 外部声明函数，使其能被其他 .c 文件调用。
+ **条件分支**：进行程序逻辑选择。
+ **循环语句**：控制程序的进行、停止与跳转。
+ **随机数生成**：生成随机字符串来制造唯一的订单号。
+ **Makefile**：工程管理，make 命令编译所有 .c 文件成 .o 文件再编译成可执行文件。

## 5. 目录结构描述

```bash
├── inc								# 存放.h文件
│   ├── callback.h
│   ├── display.h
│   ├── info_list.h
│   ├── kernel_list.h
│   ├── lawful.h
│   ├── main.h
│   └── system.h
├── info
│   ├── customer.txt				# 用户信息记事本
│   ├── ticket.txt					# 购票信息记事本
│   ├── train.txt					# 车次信息记事本
│   ├── 注册的用户信息.xlsx			# 用户信息表格
│   ├── 购票信息.xlsx				  # 购票信息表格
│   ├── 身份证号码模拟.xlsx			# 身份证模拟表格
│   └── 车次信息.xlsx				  # 用户信息表格
├── lib								# 库文件
├── output							# 可执行文件
│   └── main
├── src								# 存放.c和.o文件
│   ├── callback.c					# 回调
│   ├── callback.o
│   ├── display.c					# 显示界面
│   ├── display.o
│   ├── info_list.c					# 内核链表存放信息
│   ├── info_list.o
│   ├── lawful.c					# 身份证合法性验证
│   ├── lawful.o
│   ├── main.c						# main函数
│   ├── main.o
│   ├── system.c					# 系统逻辑
│   └── system.o
├── Makefile						# Makefile工程配置文件
├── README.md						# 工程描述
├── 项目框架.xmind					  # 工程框架
└── 项目演示视频.mp4					 # 项目演示

```

## 6. 视频演示

<video id="video" controls="" preload="none">
    <source id="mp4" src="E:\Code\puresoft\ticket_system\项目演示视频.mp4" type="video/mp4">
</video>
