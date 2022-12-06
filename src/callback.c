/*
************************************************************************
* file name: callback.c
* author: 苏尚宇
* date: Thu Nov 24 15:20:50 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "callback.h"
#include "info_list.h"
#include "kernel_list.h"

/* 查找车次名称回调函数 */
void *find_train_name(kernel_list_node *train, void *arg)
{
	if( !strcmp(train->train_data.name, arg) )
		return train;
	return NULL;
}

/* 查找某时间车次信息回调函数 */
void *find_departure_time(kernel_list_node *train, void *arg)
{
	if( !strcmp(train->train_data.departure_time, arg) )
		return train;
	return NULL;
}

/* 查找余票数回调函数 */
void *find_train_ticket(kernel_list_node *train, void *arg)
{
	short num = *(short *)arg;
	if( train->train_data.ticket == num )
		return train;
	return NULL;
}

/* 查找出发地回调函数 */
void *find_place_dep(kernel_list_node *train, void *arg)
{
	if( !strcmp(train->train_data.place_dep, arg) )
		return train;
	return NULL;
}

/* 查找目的地回调函数 */
void *find_destination(kernel_list_node *train, void *arg)
{
	if( !strcmp(train->train_data.destination, arg) )
		return train;
	return NULL;
}

/* 查找某车次购票信息回调函数 */
void *find_ticket_train(kernel_list_node *ticket, void *arg)
{
	if( !strcmp(ticket->ticket_data.train_name, arg) )
		return ticket;
	return NULL;
}

/* 按用户ID查找购票信息回调函数 */
void *find_user_id_ticket(kernel_list_node *ticket, void *arg)
{
	short num = *(short *)arg;
	if( ticket->ticket_data.user_id == num )
		return ticket;
	return NULL;
}

/* 按姓名查找购票信息回调函数 */
void *find_user_name_ticket(kernel_list_node *ticket, void *arg)
{
	if( !strcmp(ticket->ticket_data.name, arg) )
		return ticket;
	return NULL;
}

/* 按身份证号查找用户信息回调函数 */
void *find_user_num_id_ticket(kernel_list_node *ticket, void *arg)
{
	if( !strcmp(ticket->ticket_data.num_id, arg) )
		return ticket;
	return NULL;
}

/* 按ID查找用户信息回调函数 */
void *find_user_id(kernel_list_node *customer, void *arg)
{
	short num = *(short *)arg;
	if( customer->customer_data.user_id == num )
		return customer;
	return NULL;
}

/* 按姓名查找用户信息回调函数 */
void *find_user_name(kernel_list_node *customer, void *arg)
{
	if( !strcmp(customer->customer_data.name, arg) )
		return customer;
	return NULL;
}

/* 按身份证号查找用户信息回调函数 */
void *find_user_num_id(kernel_list_node *customer, void *arg)
{
	if( !strcmp(customer->customer_data.num_id, arg) )
		return customer;
	return NULL;
}

/* 按余票升序排序回调函数 */
void *sort_ticket(kernel_list_node *arg1, kernel_list_node *arg2)
{
	if( arg1->train_data.ticket < arg2->train_data.ticket)
		return arg1;
	return NULL;
}

/* 按发车时间升序排序回调函数 */
void *sort_time(kernel_list_node *arg1, kernel_list_node *arg2)
{
	if( strcmp(arg1->train_data.departure_time, arg2->train_data.departure_time)>0 )
		return arg1;
	return NULL;
}

/* 按票价高低排序回调函数 */
void *sort_price(kernel_list_node *arg1, kernel_list_node *arg2)
{
	if( arg1->train_data.ticket_price > arg2->train_data.ticket_price)
		return arg1;
	return NULL;
}

/* 出发地修改回调函数 */
void *revise_place(kernel_list_node *arg1, void *arg2)
{
	char place[10];
	printf("修改出发地：");
	scanf("%s", place);
	strcpy(arg1->train_data.place_dep, place);

	return NULL;
}

/* 目的地修改回调函数 */
void *revise_destination(kernel_list_node *arg1, void *arg2)
{
	char place[10];
	printf("修改目的地：");
	scanf("%s", place);
	strcpy(arg1->train_data.destination, place);

	return NULL;
}

/* 发车时间修改回调函数 */
void *revise_departure_time(kernel_list_node *arg1, void *arg2)
{
	char time[30];
	printf("修改发车时间：");
	scanf("%s", time);
	strcpy(arg1->train_data.departure_time, time);

	return NULL;
}

/* 行程时间修改回调函数 */
void *revise_travel_time(kernel_list_node *arg1, void *arg2)
{
	char time[30];
	printf("修改行程时间：");
	scanf("%s", time);
	strcpy(arg1->train_data.travel_time, time);

	return NULL;
}

/* 票价修改回调函数 */
void *revise_travel_price(kernel_list_node *arg1, void *arg2)
{
	int price;
	printf("修改票价：");
	scanf("%d", &price);
	arg1->train_data.ticket_price = price;

	return NULL;
}

/* 车次修改回调函数 */
void *revise_train(kernel_list_node *arg1, void *arg2)
{
	char train[10];
	printf("修改车次为：");
	scanf("%s", train);
	strcpy(arg1->ticket_data.train_name, train);

	return NULL;
}

/* 座位修改回调函数 */
void *revise_seat(kernel_list_node *arg1, void *arg2)
{
	char seat[10];
	printf("修改座位为：");
	scanf("%s", seat);
	strcpy(arg1->ticket_data.seat_num, seat);

	return NULL;
}

/* 余额减少回调函数 */
void *revise_reduce_balance(kernel_list_node *arg1, void *arg2)
{
	double *temp = (double *)arg2;
	arg1->customer_data.balance -= *temp;

	return NULL;
}

/* 余额增加回调函数 */
void *revise_add_balance(kernel_list_node *arg1, void *arg2)
{
	double *temp = (double *)arg2;
	arg1->customer_data.balance += *temp;

	return NULL;
}

/* 用户密码修改回调函数 */
void *revise_passwd(kernel_list_node *arg1, void *arg2)
{
	char passwd[20];
	printf("请输入修改密码: ");
	scanf("%s", passwd);
	strcpy(arg1->customer_data.passwd, passwd);

	return NULL;
}

/* 交换数据函数 */
void swap_data(int *arg1, int *arg2)
{
	int tmp;
	tmp = *arg1;
	*arg1 = *arg2;
	*arg2 = tmp;
}
/* 交换字符串函数 */
void swap_str(char *arg1, char *arg2)
{
	char tmp[20];
	strcpy(tmp, arg1);
	strcpy(arg1, arg2);
	strcpy(arg2, tmp);	
}

