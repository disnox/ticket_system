/*
************************************************************************
* file name: info_list.c
* author: 苏尚宇
* date: Wed Nov 23 19:59:46 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "info_list.h"
#include "callback.h"
#include "system.h"
#include "lawful.h"


struct list_head train_node;
struct list_head ticket_node;
struct list_head customer_node;

char train_buff[SIZE];
char ticket_buff[SIZE];
char customer_buff[SIZE];
/*
************************************************************************
* @brief      read_file_train_info()
* @param      void
* @return     void
* describe:   从train.txt读入购票信息
************************************************************************
*/    
void read_file_train_info(void)
{
	train_info train_tmp;
	kernel_list_node *kernel_train_node = NULL;

	FILE *fp = NULL;

	fp = fopen("./info/train.txt", "r");

	fgets(train_buff, SIZE-1, (FILE*)fp);

	while(!feof(fp))
	{
		if( 8 == fscanf( fp, "%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", train_tmp.name, train_tmp.place_dep, \
		train_tmp.destination, train_tmp.departure_time, train_tmp.travel_time, &(train_tmp.ticket), \
		&(train_tmp.ticket_price), &(train_tmp.seats) ) )
		{
			kernel_train_node = (kernel_list_node *)malloc(sizeof(kernel_list_node));

			memcpy(&(kernel_train_node->train_data), &train_tmp, sizeof(kernel_list_node));

			list_add_tail(&(kernel_train_node->point_node), &(train_node));
		}	
	}

	fclose(fp);
}
/*
************************************************************************
* @brief      read_file_ticket_info()
* @param      void
* @return     void
* describe:   从ticket.txt读入购票信息
************************************************************************
*/    
void read_file_ticket_info(void)
{
	ticket_info ticket_tmp;
	kernel_list_node *kernel_ticket_node = NULL;

	FILE *fp = NULL;

	fp = fopen("./info/ticket.txt", "r");

	fgets(ticket_buff, 	SIZE-1, (FILE*)fp);
	
	while(!feof(fp))
	{
		if(7 == fscanf(fp, "%s\t%d\t%s\t%s\t%s\t%s\t%s\n", ticket_tmp.name, &(ticket_tmp.user_id), \
		ticket_tmp.gender, ticket_tmp.num_id, ticket_tmp.train_name, ticket_tmp.seat_num, ticket_tmp.order_num))
		{
			kernel_ticket_node = (kernel_list_node *)malloc(sizeof(kernel_list_node));

			memcpy(&(kernel_ticket_node->ticket_data), &ticket_tmp, sizeof(kernel_list_node));

			list_add_tail(&(kernel_ticket_node->point_node), &(ticket_node));
		}	
	}

	fclose(fp);
}
/*
************************************************************************
* @brief      read_file_customer_info()
* @param      void
* @return     void
* describe:   从customer.txt读入乘客信息
************************************************************************
*/    
void read_file_customer_info(void)
{
	customer_info customer_tmp;
	kernel_list_node *kernel_customer_node = NULL;

	FILE *fp = NULL;

	fp = fopen("./info/customer.txt", "r");

	fgets(customer_buff, SIZE-1, (FILE*)fp);

	while(!feof(fp))
	{
		if(7 == fscanf(fp, "%s\t%d\t%s\t%s\t%s\t%lf\t%s\n", customer_tmp.name, &(customer_tmp.user_id), \
		customer_tmp.gender, customer_tmp.num_id, customer_tmp.phone_number, &(customer_tmp.balance), customer_tmp.passwd))
		{
			kernel_customer_node = (kernel_list_node *)malloc(sizeof(kernel_list_node));

			memcpy(&(kernel_customer_node->customer_data), &customer_tmp, sizeof(kernel_list_node));

			list_add_tail(&(kernel_customer_node->point_node), &(customer_node));
		}	
	}
	fclose(fp);
}
/*
************************************************************************
* @brief      print_train_all_info()
* @param      void
* @return     void
* describe:   全部打印从train.txt读入的车次信息
************************************************************************
*/  
void print_train_all_info(void)
{
	struct list_head *pos;
	kernel_list_node *train = NULL;

	printf("%s", train_buff);

	list_for_each(pos, &(train_node))
	{
		train = container_of(pos, kernel_list_node, point_node);
		printf("%s\t%s\t", train->train_data.name, train->train_data.place_dep);
		printf("%s\t%s\t", train->train_data.destination, train->train_data.departure_time);
		printf("%s\t\t%d\t", train->train_data.travel_time,train->train_data.ticket);
		printf("%d\t%d\n", train->train_data.ticket_price, train->train_data.seats);
	}
	printf("\n");
}
/*
************************************************************************
* @brief      print_ticket_all_info()
* @param      void
* @return     void
* describe:   全部打印从ticket.txt读入的购票信息
************************************************************************
*/  
void print_ticket_all_info(void)
{
	struct list_head *pos;
	kernel_list_node *ticket = NULL;

	printf("%s", ticket_buff);

	list_for_each(pos, &(ticket_node))
	{
		ticket = container_of(pos, kernel_list_node, point_node);
		printf("%s\t%d\t", ticket->ticket_data.name, ticket->ticket_data.user_id);
		printf("%s\t%s\t", ticket->ticket_data.gender, ticket->ticket_data.num_id);
		printf("%s\t%s\t", ticket->ticket_data.train_name,ticket->ticket_data.seat_num);
		printf("%s\n", ticket->ticket_data.order_num);
	}
	printf("\n");
}
/*
************************************************************************
* @brief      print_custom_info()
* @param      void
* @return     void
* describe:   全部打印从customer.txt读入的乘客信息
************************************************************************
*/  
void print_customer_all_info(void)
{
	struct list_head *pos;
	kernel_list_node *customer = NULL;

	printf("%s", customer_buff);

	list_for_each(pos, &(customer_node))
	{
		customer = container_of(pos, kernel_list_node, point_node);
		printf("%s\t%d\t", customer->customer_data.name, customer->customer_data.user_id);
		printf("%s\t%s\t", customer->customer_data.gender, customer->customer_data.num_id);
		printf("%s\t%.2lf\t", customer->customer_data.phone_number,customer->customer_data.balance);
		printf("%s\n", customer->customer_data.passwd);
	}
	printf("\n");
}
/*
************************************************************************
* @brief      print_train_one_info()
* @param      train 内核头结点
* @return     void
* describe:   单次打印从train.txt读入的车次信息
************************************************************************
*/  
void print_train_one_info(kernel_list_node *train)
{
	printf("%s\t%s\t", train->train_data.name, train->train_data.place_dep);
	printf("%s\t%s\t", train->train_data.destination, train->train_data.departure_time);
	printf("%s\t\t%d\t", train->train_data.travel_time,train->train_data.ticket);
	printf("%d\t%d\n", train->train_data.ticket_price, train->train_data.seats);
}
/*
************************************************************************
* @brief      print_ticket_one_info()
* @param      ticket 内核头结点
* @return     void
* describe:   全部打印从ticket.txt读入的购票信息
************************************************************************
*/  
void print_ticket_one_info(kernel_list_node *ticket)
{
	printf("%s\t%d\t", ticket->ticket_data.name, ticket->ticket_data.user_id);
	printf("%s\t%s\t", ticket->ticket_data.gender, ticket->ticket_data.num_id);
	printf("%s\t%s\t", ticket->ticket_data.train_name,ticket->ticket_data.seat_num);
	printf("%s\n", ticket->ticket_data.order_num);
}
/*
************************************************************************
* @brief      print_customer_one_info()
* @param      customer 内核头结点
* @return     void
* describe:   全部打印从customer.txt读入的乘客信息
************************************************************************
*/  
void print_customer_one_info(kernel_list_node *customer)
{
	printf("%s\t%d\t", customer->customer_data.name, customer->customer_data.user_id);
	printf("%s\t%s\t", customer->customer_data.gender, customer->customer_data.num_id);
	printf("%s\t%.2lf\t", customer->customer_data.phone_number,customer->customer_data.balance);
	printf("%s\n", customer->customer_data.passwd);
}
/*
************************************************************************
* @brief      inset_train_info()
* @param      void
* @return     void
* describe:   添加车次信息到train.txt
************************************************************************
*/  
void inset_train_info(void)
{
	kernel_list_node *train = (kernel_list_node *)malloc(sizeof(kernel_list_node));
	if(train == NULL)
	{
		printf("内存分配失败\n");
		return ;
	}

	FILE *fp = fopen("./info/train.txt", "a+");

	printf("请输入车次信息\n");
	printf("----------------------\n");
	printf("请输入车次姓名：");
	scanf("%s", train->train_data.name);
	printf("请输入出发地：");
	scanf("%s", train->train_data.place_dep);
	printf("请输入目的地：");
	scanf("%s", train->train_data.destination);	
	printf("请输入出发时间：");
	scanf("%s", train->train_data.departure_time);
	printf("请输入行程时间：");
	scanf("%s", train->train_data.travel_time);
	printf("请输入车次余票：");
	scanf("%d", &(train->train_data.ticket));
	printf("请输入车次票价：");
	scanf("%d", &(train->train_data.ticket_price));
	printf("请输入车次座位：");
	scanf("%d", &(train->train_data.seats));

	list_add_tail(&(train->point_node), &(train_node));  // 将新添加的信息添加到结点末尾

	fprintf(fp, "%s\t%s\t", train->train_data.name, train->train_data.place_dep);
	fprintf(fp, "%s\t%s\t", train->train_data.destination, train->train_data.departure_time);
	fprintf(fp, "%s\t\t%d\t", train->train_data.travel_time,train->train_data.ticket);
	fprintf(fp, "%d\t%d\n", train->train_data.ticket_price, train->train_data.seats);

	fclose(fp);

	printf("信息录入成功!!!!!!! \n");
}
/*
************************************************************************
* @brief      inset_ticket_info()
* @param      void
* @return     void
* describe:   添加购票信息到ticket.txt
************************************************************************
*/  
void inset_ticket_info(kernel_list_node *arg1, kernel_list_node *arg2, void *arg3)
{
	char temp[11] = {0};
	kernel_list_node *ticket = (kernel_list_node *)malloc(sizeof(kernel_list_node));
	if(ticket == NULL)
	{
		printf("内存分配失败\n");
		return ;
	}

	FILE *fp = fopen("./info/ticket.txt", "a+");

	rand_str(temp); // 生成随机字符串

	strcpy(ticket->ticket_data.name, arg1->customer_data.name);
	ticket->ticket_data.user_id = arg1->customer_data.user_id;
	strcpy(ticket->ticket_data.gender, arg1->customer_data.gender);
	strcpy(ticket->ticket_data.num_id, arg1->customer_data.num_id);
	strcpy(ticket->ticket_data.train_name, arg2->train_data.name);
	strcpy(ticket->ticket_data.seat_num, arg3);
	strcpy(ticket->ticket_data.order_num, temp);

	list_add_tail(&(ticket->point_node), &(ticket_node));  // 将新添加的信息添加到结点末尾

	fprintf(fp, "%s\t%d\t", ticket->ticket_data.name, ticket->ticket_data.user_id);
	fprintf(fp, "%s\t%s\t", ticket->ticket_data.gender, ticket->ticket_data.num_id);
	fprintf(fp, "%s\t%s\t", ticket->ticket_data.train_name,ticket->ticket_data.seat_num);
	fprintf(fp, "%s\n", ticket->ticket_data.order_num);

	fclose(fp);
}
/*
************************************************************************
* @brief      inset_customer_info()
* @param      void
* @return     void
* describe:   添加购票信息到customer.txt
************************************************************************
*/  
void inset_customer_info(void)
{
	kernel_list_node *customer = (kernel_list_node *)malloc(sizeof(kernel_list_node));

	if(customer == NULL)
	{
		printf("内存分配失败\n");
		return ;
	}

	FILE *fp = fopen("./info/customer.txt", "a+");

	printf("请输入用户信息\n");
	printf("----------------------\n");
	printf("请输入姓名：");
	scanf("%s", customer->customer_data.name);
	printf("请输入用户ID：");
	scanf("%d", &(customer->customer_data.user_id));
	printf("请输入乘客性别：");
	scanf("%s", customer->customer_data.gender);	
	printf("请输入身份证号：");
	scanf("%s", customer->customer_data.num_id);

	if(if_lawful(customer->customer_data.num_id))
	{
		printf("身份证合法，请继续\n");
		printf("请输入电话号码：");
		scanf("%s", customer->customer_data.phone_number);
		printf("请输入预充值金额：");
		scanf("%lf", &(customer->customer_data.balance));
		printf("请输入密码：");
		scanf("%s", customer->customer_data.passwd);

		list_add_tail(&(customer->point_node), &(customer_node));  // 将新添加的信息添加到结点末尾

		fprintf(fp, "%s\t%d\t", customer->customer_data.name, customer->customer_data.user_id);
		fprintf(fp, "%s\t%s\t", customer->customer_data.gender, customer->customer_data.num_id);
		fprintf(fp, "%s\t%.2lf\t", customer->customer_data.phone_number,customer->customer_data.balance);
		fprintf(fp, "%s\n", customer->customer_data.passwd);

		fclose(fp);

		printf("信息录入成功!!!!!!! \n");
	}
	else
		printf("身份证不合法!!!!!!! \n");
}
/*
************************************************************************
* @brief      find_train_info()
* @param      void
* @return     void
* describe:   查找车次信息
************************************************************************
*/  
void find_train_info(fun_t handle, void *arg)
{
	int find_flag = 0;

	struct list_head *pos = NULL;
	kernel_list_node *train = NULL;

	printf("----------------------\n");
	printf("%s", train_buff);
	
	list_for_each(pos, &train_node)
	{
		train = container_of(pos, kernel_list_node, point_node);
		if(handle(train, arg) != NULL)
		{
			print_train_one_info(train);   // 单次打印该信息
			find_flag = 1;
		}
	}	
	if(find_flag == 0)
		printf("信息查找失败!!!!!!\n");
	else
		printf("信息查找成功!!!!!!\n");
}
/*
************************************************************************
* @brief      find_ticket_info()
* @param      void
* @return     void
* describe:   查找购票信息
************************************************************************
*/  
void find_ticket_info(fun_t handle, void *arg)
{
	int find_flag = 0;

	struct list_head *pos = NULL;
	kernel_list_node *ticket = NULL;

	printf("----------------------\n");
	printf("%s", ticket_buff);

	list_for_each(pos, &ticket_node)
	{
		ticket = container_of(pos, kernel_list_node, point_node);

		if(handle(ticket, arg) != NULL)
		{
			print_ticket_one_info(ticket);   // 单次打印该信息
			find_flag = 1;
		}
	}	
	if(find_flag == 0)
		printf("信息查找失败!!!!!!\n");
	else
		printf("信息查找成功!!!!!!\n");
}
/*
************************************************************************
* @brief      find_customer_info()
* @param      void
* @return     void
* describe:   查找用户信息
************************************************************************
*/  
void find_customer_info(fun_t handle, void *arg)
{
	int find_flag = 0;

	struct list_head *pos = NULL;
	kernel_list_node *customer = NULL;

	printf("----------------------\n");
	printf("%s", customer_buff);

	list_for_each(pos, &customer_node)
	{
		customer = container_of(pos, kernel_list_node, point_node);

		if(handle(customer, arg) != NULL)
		{
			print_customer_one_info(customer);   // 单次打印该信息
			find_flag = 1;
		}
	}	
	if(find_flag == 0)
		printf("信息查找失败!!!!!!\n");
	else
		printf("信息查找成功!!!!!!\n");
}
/*
************************************************************************
* @brief      delete_train_info()
* @param      void
* @return     void
* describe:   删除车次信息
************************************************************************
*/  
void delete_train_info(void)
{
	char train_name[10];
	int del_flag = 0;

	print_train_all_info();  	// 打印全部信息再选择删除

	printf("请输入要删除的车次信息：");
	scanf("%s", train_name);

	struct list_head *pos = NULL;
	struct list_head *n = NULL;
	kernel_list_node *train = NULL;

	list_for_each_safe(pos, n, &train_node)
	{
		train = container_of(pos, kernel_list_node, point_node);

		if( !strcmp(train->train_data.name, train_name) )
		{
			list_del( &(train->point_node) );
			del_flag = 1;
		}
	}	
	if(del_flag == 0)
		printf("信息删除失败!!!!!!\n");
	else
		printf("信息删除成功!!!!!!\n");
	preserve_train_info_file();
}
/*
************************************************************************
* @brief      delete_ticket_info()
* @param      void
* @return     void
* describe:   删除购票信息
************************************************************************
*/  
void delete_ticket_info(char *train_name)
{
	int del_flag = 0;

	struct list_head *pos = NULL;
	struct list_head *n = NULL;
	kernel_list_node *ticket = NULL;

	list_for_each_safe(pos, n, &ticket_node)
	{
		ticket = container_of(pos, kernel_list_node, point_node);

		if( !strcmp(ticket->ticket_data.train_name, train_name) )
		{
			list_del( &(ticket->point_node) );
			del_flag = 1;
		}
	}
	// if(del_flag == 0)
	// 	printf("信息删除失败!!!!!!\n");
	// else
	// 	printf("信息删除成功!!!!!!\n");
	preserve_ticket_info_file();
}

/*
************************************************************************
* @brief      delete_customer_info()
* @param      void
* @return     void
* describe:   删除用户信息
************************************************************************
*/  
void delete_customer_info(void)
{
	int user_id;
	int del_flag = 0;

	print_customer_all_info();  	// 打印全部信息再选择删除

	printf("请输入要删除的用户id：");
	scanf("%d", &user_id);

	struct list_head *pos = NULL;
	struct list_head *n = NULL;
	kernel_list_node *customer = NULL;

	list_for_each_safe(pos, n, &customer_node)
	{
		customer = container_of(pos, kernel_list_node, point_node);

		if( customer->customer_data.user_id == user_id )
		{
			list_del( &(customer->point_node) );
			del_flag = 1;
		}
	}
	if(del_flag == 0)
		printf("信息删除失败!!!!!!\n");
	else
		printf("信息删除成功!!!!!!\n");	
	preserve_customer_info_file();
}
/*
************************************************************************
* @brief      rearrange()
* @param      void
* @return     void
* describe:   排序
************************************************************************
*/  
void rearrange(fun handle)
{	
	struct list_head *pos1;
	struct list_head *pos2;
	kernel_list_node *p1;
	kernel_list_node *p2;

	list_for_each(pos1 , &train_node)				//冒泡排序
	{
		list_for_each(pos2 , &train_node)
		{
			p1 = list_entry(pos1, kernel_list_node, point_node);
			p2 = list_entry(pos2, kernel_list_node, point_node);
			if(handle(p1, p2))
			{
				swap_str(p1->train_data.name, p2->train_data.name);
				swap_str(p1->train_data.place_dep, p2->train_data.place_dep);
				swap_str(p1->train_data.destination, p2->train_data.destination);
				swap_str(p1->train_data.departure_time, p2->train_data.departure_time);
				swap_str(p1->train_data.travel_time, p2->train_data.travel_time);
				swap_data(&(p1->train_data.ticket), &(p2->train_data.ticket));
				swap_data(&(p1->train_data.ticket_price), &(p2->train_data.ticket_price));
				swap_data(&(p1->train_data.seats), &(p2->train_data.seats));
			}
		}
	}
}
/*
************************************************************************
* @brief      revise_train_info()
* @param      void
* @return     void
* describe:   修改可选的车次信息
************************************************************************
*/  
void revise_train_info(fun_t handle, void *arg)
{
	char train_name[10];
	int revise_flag = 0;

	print_train_all_info();  	// 打印全部信息再选择修改
	
	printf("请输入要修改的车次：");
	scanf("%s", train_name);
	printf("----------------------\n");

	struct list_head *pos = NULL;
	kernel_list_node *train = NULL;

	printf("%s", train_buff);

	list_for_each(pos, &train_node)
	{
		train = container_of(pos, kernel_list_node, point_node);

		if( !strcmp(train->train_data.name, train_name) )
		{
			printf("修改前\n");
			print_train_one_info(train);
			printf("----------------------\n");
			handle(train, arg);
			printf("----------------------\n");
			printf("修改后\n");
			print_train_one_info(train);
			revise_flag = 1;
		}
	}
	if(revise_flag == 0)
		printf("信息修改失败!!!!!!\n");
	else
		printf("信息修改成功!!!!!!\n");	
	preserve_train_info_file();
}
/*
************************************************************************
* @brief      revise_ticket_info()
* @param      void
* @return     void
* describe:   修改用户购票的信息
************************************************************************
*/  
void revise_ticket_info(fun_t handle, void *arg)
{
	int user_id;
	int revise_flag = 0;

	print_ticket_all_info();  	// 打印全部信息再选择修改

	printf("请输入要修改的用户ID：");
	scanf("%d", &user_id);
	printf("----------------------\n");

	struct list_head *pos = NULL;
	kernel_list_node *ticket = NULL;

	printf("%s", ticket_buff);

	list_for_each(pos, &ticket_node)
	{
		ticket = container_of(pos, kernel_list_node, point_node);

		if( ticket->ticket_data.user_id == user_id )
		{
			printf("修改前\n");
			print_ticket_one_info(ticket);
			printf("----------------------\n");
			handle(ticket, arg);
			printf("----------------------\n");
			printf("修改后\n");
			print_ticket_one_info(ticket);
			revise_flag = 1;
		}
	}
	if(revise_flag == 0)
		printf("信息修改失败!!!!!!\n");
	else
		printf("信息修改成功!!!!!!\n");	
	preserve_ticket_info_file();
}
/*
************************************************************************
* @brief      revise_user_info()
* @param      void
* @return     void
* describe:   修改用户的信息
************************************************************************
*/  
void revise_user_info(fun_t handle, void *arg1, void *arg2)
{
	struct list_head *pos = NULL;
	kernel_list_node *customer = NULL;

	list_for_each(pos, &customer_node)
	{
		customer = container_of(pos, kernel_list_node, point_node);
		
		if( (!strcmp(customer->customer_data.num_id, arg2)) ||\
			(!strcmp(customer->customer_data.phone_number, arg2)))
		{
			handle(customer, arg1);
		}

	}
	preserve_customer_info_file();
}
/*
************************************************************************
* @brief      preserve_train_info_file()
* @param      void
* @return     void
* describe:   保存车次所有信息
************************************************************************
*/  
void preserve_train_info_file(void)
{
	struct list_head *pos = NULL;
	kernel_list_node *train = NULL;

	FILE *fp = fopen("./info/train.txt", "w+");

	fprintf(fp, "%s", train_buff);

	list_for_each(pos, &train_node)
	{
		train = container_of(pos, kernel_list_node, point_node);

		fprintf(fp, "%s\t%s\t", train->train_data.name, train->train_data.place_dep);
		fprintf(fp, "%s\t%s\t", train->train_data.destination, train->train_data.departure_time);
		fprintf(fp, "%s\t\t%d\t", train->train_data.travel_time,train->train_data.ticket);
		fprintf(fp, "%d\t%d\n", train->train_data.ticket_price, train->train_data.seats);
	}

	fclose(fp);

}
/*
************************************************************************
* @brief      preserve_ticket_info_file()
* @param      void
* @return     void
* describe:   保存购票所有信息
************************************************************************
*/  
void preserve_ticket_info_file(void)
{
	struct list_head *pos = NULL;
	kernel_list_node *ticket = NULL;

	FILE *fp = fopen("./info/ticket.txt", "w+");

	fprintf(fp, "%s", ticket_buff);

	list_for_each(pos, &ticket_node)
	{

		ticket = container_of(pos, kernel_list_node, point_node);

		fprintf(fp, "%s\t%d\t", ticket->ticket_data.name, ticket->ticket_data.user_id);
		fprintf(fp, "%s\t%s\t", ticket->ticket_data.gender, ticket->ticket_data.num_id);
		fprintf(fp, "%s\t%s\t", ticket->ticket_data.train_name,ticket->ticket_data.seat_num);
		fprintf(fp, "%s\n", ticket->ticket_data.order_num);
	}

	fclose(fp);
}
/*
************************************************************************
* @brief      preserve_customer_info_file()
* @param      void
* @return     void
* describe:   保存用户信息
************************************************************************
*/  
void preserve_customer_info_file(void)
{
	struct list_head *pos = NULL;
	kernel_list_node *customer = NULL;

	FILE *fp = fopen("./info/customer.txt", "w+");

	fprintf(fp, "%s", customer_buff);

	list_for_each(pos, &customer_node)
	{

		customer = container_of(pos, kernel_list_node, point_node);

		fprintf(fp, "%s\t%d\t", customer->customer_data.name, customer->customer_data.user_id);
		fprintf(fp, "%s\t%s\t", customer->customer_data.gender, customer->customer_data.num_id);
		fprintf(fp, "%s\t%.2lf\t", customer->customer_data.phone_number,customer->customer_data.balance);
		fprintf(fp, "%s\n", customer->customer_data.passwd);
	}

	fclose(fp);
}



