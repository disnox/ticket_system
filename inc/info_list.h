/*
************************************************************************
* file name: info_list.h
* author: 苏尚宇
* date: Wed Nov 23 20:00:05 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#ifndef _INFO_LIST_H__
#define _INFO_LIST_H__

#include "kernel_list.h"

#define SIZE 1024

extern struct list_head train_node;
extern struct list_head ticket_node;
extern struct list_head customer_node;

extern char train_buff[SIZE];
extern char ticket_buff[SIZE];
extern char customer_buff[SIZE];

// 车次信息结点设计
typedef struct
{
	char name[20];					    // 车次姓名
	char place_dep[10] ;			    // 出发地
	char destination[10];				// 目的地
	char departure_time[30];			// 出发时间
	char travel_time[20];			    // 行程时间
	int  ticket;					    // 余票
    int  ticket_price;                  // 票价
    int  seats;                         // 座位数  
}train_info;

// 购票信息结点设计
typedef struct
{
	char name[20];					    // 乘客姓名
    int user_id;					    // 乘客用户ID
	char gender[10];				    // 乘客性别
	char num_id[20];				    // 身份证号
	char train_name[20];			    // 车次
	char seat_num[20];					// 座位号
    char order_num[20];					// 订单号
}ticket_info;

// 客户信息结点设计
typedef struct
{
	char name[20];					    // 乘客姓名
	int user_id;					    // 乘客用户ID
	char gender[10];				    // 乘客性别
	char num_id[20];				    // 身份证号
	char phone_number[20];			    // 电话号码
	double balance;					    // 余额
	char passwd[20];				    // 密码
}customer_info;

// 内核结点
typedef struct
{
    train_info train_data;              // 车次信息数据域 
    ticket_info ticket_data;            // 购票信息数据域 
    customer_info customer_data;        // 客户信息数据域  
	struct list_head point_node;        // 内核链表
}kernel_list_node;

typedef void *(*fun_t)(kernel_list_node *, void *);
typedef void *(*fun)(kernel_list_node *, kernel_list_node *);

/* 文件读取函数 */
extern void read_file_train_info(void);
extern void read_file_ticket_info(void);
extern void read_file_customer_info(void);

/* 信息打印函数 */
extern void print_train_all_info(void);
extern void print_ticket_all_info(void);
extern void print_customer_all_info(void);
extern void print_train_one_info(kernel_list_node *train);
extern void print_ticket_one_info(kernel_list_node *ticket);
extern void print_customer_one_info(kernel_list_node *customer);

/* 插入信息函数 */
extern void inset_train_info(void);
extern void inset_ticket_info(kernel_list_node *arg1, kernel_list_node *arg2, void *arg3);
extern void inset_customer_info(void);

/* 查找信息函数 */
extern void find_train_info(fun_t handle, void *arg);
extern void find_ticket_info(fun_t handle, void *arg);
extern void find_customer_info(fun_t handle, void *arg);

/* 删除信息函数 */
extern void delete_train_info(void);
extern void delete_ticket_info(char *train_name);
extern void delete_customer_info(void);

/* 保存信息函数 */
extern void preserve_train_info_file(void);
extern void preserve_ticket_info_file(void);
extern void preserve_customer_info_file(void);

/* 排序函数 */
extern void rearrange(fun handle);

/* 修改函数 */
extern void revise_train_info(fun_t handle, void *arg);
extern void revise_ticket_info(fun_t handle, void *arg);
extern void revise_user_info(fun_t handle, void *arg1, void *arg2);

#endif
