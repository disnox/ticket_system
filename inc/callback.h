/*
************************************************************************
* file name: callback.h
* author: 苏尚宇
* date: Thu Nov 24 15:20:59 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#ifndef _CALLBACK_H__
#define _CALLBACK_H__

#include "info_list.h"

/* 查找回调函数 */
extern void *find_train_name(kernel_list_node *train, void *arg);
extern void *find_departure_time(kernel_list_node *train, void *arg);
extern void *find_train_ticket(kernel_list_node *train, void *arg);
extern void *find_place_dep(kernel_list_node *train, void *arg);
extern void *find_destination(kernel_list_node *train, void *arg);
extern void *find_ticket_train(kernel_list_node *ticket, void *arg);

/* 查找用户购票信息回调函数 */
extern void *find_user_id_ticket(kernel_list_node *ticket, void *arg);
extern void *find_user_name_ticket(kernel_list_node *ticket, void *arg);
extern void *find_user_num_id_ticket(kernel_list_node *ticket, void *arg);

/* 查找用户信息回调函数 */
extern void *find_user_id(kernel_list_node *customer, void *arg);
extern void *find_user_name(kernel_list_node *customer, void *arg);
extern void *find_user_num_id(kernel_list_node *customer, void *arg);

/* 修改回调函数 */
extern void *revise_place(kernel_list_node *arg1, void *arg2);
extern void *revise_destination(kernel_list_node *arg1, void *arg2);
extern void *revise_departure_time(kernel_list_node *arg1, void *arg2);
extern void *revise_travel_time(kernel_list_node *arg1, void *arg2);
extern void *revise_travel_price(kernel_list_node *arg1, void *arg2);
extern void *revise_train(kernel_list_node *arg1, void *arg2);
extern void *revise_seat(kernel_list_node *arg1, void *arg2);
extern void *revise_reduce_balance(kernel_list_node *arg1, void *arg2);
extern void *revise_add_balance(kernel_list_node *arg1, void *arg2);
extern void *revise_passwd(kernel_list_node *arg1, void *arg2);

/* 排序回调函数 */  
extern void *sort_ticket(kernel_list_node *arg1, kernel_list_node *arg2);
extern void *sort_time(kernel_list_node *arg1, kernel_list_node *arg2);
extern void *sort_price(kernel_list_node *arg1, kernel_list_node *arg2);

/* 交换函数 */
extern void swap_data(int *arg1, int *arg2);
extern void swap_str(char *arg1, char *arg2);

#endif
