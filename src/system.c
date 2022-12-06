/*
************************************************************************
* file name: system.c
* author: 苏尚宇
* date: Sat Nov 19 10:41:48 CST 2022
* path: /mnt/e/Data/yueq/work/purchasing_management_system
* describe: NULL
************************************************************************
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "system.h"
#include "display.h"
#include "info_list.h"
#include "callback.h"

int opt1, opt2, opt3, opt4, opt5, opt6, opt7;
int opt8, opt9, opt10, opt11, opt12, opt13;
int admin_login_flag, user_login_flag;
char buf[30];

/*
************************************************************************
* @brief      rand_str()
* @param      void
* @return     void
* describe:   生成随机字符串作为订单号
************************************************************************
*/  
void rand_str(char *str)
{
	int i;
    srand(time(NULL));//通过时间函数设置随机数种子，使得每次运行结果随机。
    for(i = 0; i < 10; i ++)
    {
        str[i] = rand()%('z'-'a' + 1) + 'a'; //生成要求范围内的随机数。
    }
}
/*
************************************************************************
* @brief      main_control()
* @param      void
* @return     void
* describe:   主控制系统
************************************************************************
*/  
void main_control(void)
{	
	int n = 0;
	menu_display();
	printf("请输入：");
	scanf("%d", &n);
	switch(n)
	{
		case 1: 
			user_login(); 
			while(1){
				user_control();
				if(opt8 == 7) break;
			}
			break;
		case 2:
			admin_login();
			while (1){
				admin_control();
				if(opt1 == 3) break;
			}
			break;
		case 3: 
			system("clear");
			inset_customer_info(); 
			exit_enter(); 
			break;			
		case 4: revise_user_passwd(); break;	
		case 5: exit(0); break;	
	}
}
/*
************************************************************************
* @brief      admin_control()
* @param      void
* @return     void
* describe:   管理员控制系统
************************************************************************
*/  
void admin_control(void)
{
	if(admin_login_flag)
	{
		admin_display();
		printf("请选择你的操作：");
		scanf("%d", &opt1);
		switch (opt1)
		{
			case 1: 
				while(1)
				{
					admin_train_display(); 
					if(opt2 == 5) break;	// 返回上一级菜单
					admin_train();
				}
				break;
			case 2:
				while(1)
				{
					admin_user_display(); 
					if(opt3 == 6) break;  // 返回上一级菜单
					admin_user();
				}
				break;
		}
	}
}
/*
************************************************************************
* @brief      admin_login()
* @param      void
* @return     void
* describe:   管理员登录
************************************************************************
*/  
void admin_login(void)
{
	char user_name[10];
	unsigned int user_passwd;
	unsigned int n;

	admin_login_flag = 0;
	system("clear");
	printf("用户名：");
	scanf("%s", user_name);
	printf("密码：");
	scanf("%u", &user_passwd);
	if( (!strcmp(user_name, "admin")) && (user_passwd == 123456) )
	{
		printf("登录成功\n");
		admin_login_flag = 1;
	}
}
/*
************************************************************************
* @brief      admin_login()
* @param      void
* @return     void
* describe:   管理员车次信息管理
************************************************************************
*/  
void admin_train(void)
{
	system("clear");
	switch (opt2)
	{
		case 1: inset_train_info(); exit_enter(); break;
		case 2: delete_train_info(); exit_enter(); break;
		case 3: 
			while(1){
				if(opt4 == 7) break;
				admin_find(); 
			}
			break;
		case 4: 
			while(1){
				if(opt5 == 6) break;
				admin_revise();
			}
		 	break;
		default:break;
	}
}
/*
************************************************************************
* @brief      admin_find()
* @param      void
* @return     void
* describe:   管理员信息查询
************************************************************************
*/  
void admin_find(void)
{
	admin_train_find_display();
	switch (opt4)
	{
		case 1: 
			system("clear");
			printf("请输入要查找的车次：");

			char train_name[10];
			scanf("%s", train_name);
			find_train_info(find_train_name, train_name);
			exit_enter();
			break;
		case 2: 
			system("clear");
			printf("请输入要查找的车次：");
			char train_ticket_name[10];
			scanf("%s", train_ticket_name);
			find_ticket_info(find_ticket_train, train_ticket_name);
			exit_enter();
			break;
		case 3:
			system("clear");
			printf("请输入要查找的时间：");
			char departure_time[30];
			scanf("%s", departure_time);
			find_train_info(find_departure_time, departure_time);
			exit_enter();
			break;
		case 4: 
			system("clear");
			rearrange(sort_time);
			print_train_all_info();
			exit_enter();
			break;
		case 5: 
			system("clear");
			rearrange(sort_ticket);
			print_train_all_info();
			exit_enter();
			break;
		case 6: 
			system("clear");
			rearrange(sort_price);
			print_train_all_info();
			exit_enter();
			break;
		default:
			break;
	}
}
/*
************************************************************************
* @brief      admin_revise()
* @param      void
* @return     void
* describe:   管理员信息修改
************************************************************************
*/  
void admin_revise(void)
{
	admin_train_revise_display();
	switch (opt5)
	{
		case 1: 
			system("clear");
			revise_train_info(revise_place, NULL);
			exit_enter();
			break;
		case 2: 
			system("clear");
			revise_train_info(revise_destination, NULL);
			exit_enter();
			break;
		case 3:
			system("clear");
			revise_train_info(revise_departure_time, NULL);
			exit_enter();
			break;
		case 4: 
			system("clear");
			revise_train_info(revise_travel_time, NULL);
			exit_enter();
			break;
		case 5: 
			system("clear");
			revise_train_info(revise_travel_price, NULL);
			exit_enter();
			break;
		default:
			break;
	}
}
/*
************************************************************************
* @brief      admin_revise()
* @param      void
* @return     void
* describe:   管理员管理用户信息
************************************************************************
*/  
void admin_user(void)
{
	system("clear");
	switch (opt3)
	{
		case 1: inset_customer_info();  exit_enter(); break;
		case 2: delete_customer_info();  exit_enter(); break;
		case 3: 
			while (1){
				admin_user_find();
				if(opt6 == 4) break;
			}
			break;
		case 4: 
			while(1){
				admin_user_ticket_find();
				if(opt6 == 4) break;
			}
			break;
		case 5: 
			while(1){
				admin_revise_user();
				if(opt7 == 3) break;
			}
			break;

		default:
			break;
	}

}
/*
************************************************************************
* @brief      admin_user_find()
* @param      void
* @return     void
* describe:   管理员查找用户信息
************************************************************************
*/  
void admin_user_find(void)
{
	admin_find_display();
	switch(opt6)
	{
		case 1: 
			system("clear");
			printf("请输入要查找的用户姓名：");
			char user_name[10];
			scanf("%s", user_name);
			find_customer_info(find_user_name, user_name);
			exit_enter();
			break;
		case 2:
			system("clear");
			printf("请输入要查找的用户身份证号：");
			char num_id[30];
			scanf("%s", num_id);
			find_customer_info(find_user_num_id, num_id);
			exit_enter();
			break;
		case 3:
			system("clear");
			printf("请输入要查找的用户ID：");
			int user_id;
			scanf("%d", &user_id);
			find_customer_info(find_user_id, &user_id);
			exit_enter();
			break;
	}
}
/*
************************************************************************
* @brief      admin_user_ticket_find()
* @param      void
* @return     void
* describe:   管理员查找用户购票信息
************************************************************************
*/  
void admin_user_ticket_find(void)
{
	admin_find_display();
	switch(opt6)
	{
		case 1: 
			system("clear");
			printf("请输入要查找的用户姓名：");
			char user_name[10];
			scanf("%s", user_name);
			find_ticket_info(find_user_name_ticket, user_name);
			exit_enter();
			break;
		case 2:
			system("clear");
			printf("请输入要查找的用户身份证号：");
			char num_id[30];
			scanf("%s", num_id);
			find_ticket_info(find_user_num_id_ticket, num_id);
			exit_enter();
			break;
		case 3:
			system("clear");
			printf("请输入要查找的用户ID：");
			int user_id;
			scanf("%d", &user_id);
			find_ticket_info(find_user_id_ticket, &user_id);
			exit_enter();
			break;
	}
}
/*
************************************************************************
* @brief      admin_revise_user()
* @param      void
* @return     void
* describe:   管理员修改用户信息
************************************************************************
*/  
void admin_revise_user(void)
{
	admin_user_revise_display();
	switch (opt7)
	{
		case 1: 
			system("clear");
			revise_ticket_info(revise_train, NULL);
			exit_enter();
			break;
		case 2: 
			system("clear");
			revise_ticket_info(revise_seat, NULL);
			exit_enter();
			break;
		default:
			break;
	}
}
/*
************************************************************************
* @brief      user_login()
* @param      void
* @return     void
* describe:   用户登录
************************************************************************
*/  
void user_login(void)
{
	char user_name[30];
	char user_passwd[20];

	user_login_flag = 0;
	system("clear");
	printf("用户名：");
	scanf("%s", user_name);
	printf("密码：");
	scanf("%s", user_passwd);

	struct list_head *pos = NULL;
	kernel_list_node *customer = NULL;

	list_for_each(pos, &customer_node)
	{
		customer = container_of(pos, kernel_list_node, point_node);

		if( (!strcmp(customer->customer_data.num_id, user_name) ) ||\
		    (!strcmp(customer->customer_data.phone_number, user_name) ) &&\
			(!strcmp(customer->customer_data.passwd, user_passwd) ) )
		{
			printf("登录成功\n");
			strcpy(buf, user_name);
			user_login_flag = 1;
		}
	}
}
/*
************************************************************************
* @brief      user_control()
* @param      void
* @return     void
* describe:   用户控制台
************************************************************************
*/  
void user_control(void)
{
	if(user_login_flag)
	{
		user_display();
		switch (opt8)
		{
			case 1: 
				while(1){
					user_find();
					if(opt9 == 6) break;	// 返回上一级菜单
				}
				break;
			case 2: search_ticket(); exit_enter(); break;
			case 3: buy_ticket(); exit_enter(); break;
			case 4: retreat_ticket(find_train_name); exit_enter(); break;
			case 5:
				while(1){
					wallet();
					if(opt10 == 4) break;
				}
				break;
			case 6: revise_user_passwd(); break;
			default:
				break;
		}
	}
}
/*
************************************************************************
* @brief      user_find()
* @param      void
* @return     void
* describe:   用户查找信息
************************************************************************
*/  
void user_find(void)
{
	user_find_display();
	switch (opt9)
	{
		case 1: 
			system("clear");
			rearrange(sort_time);
			print_train_all_info();
			exit_enter();
			break;
		case 2: 
			system("clear");
			rearrange(sort_ticket);
			print_train_all_info();
			exit_enter();
			break;
		case 3: 
			system("clear");
			rearrange(sort_price);
			print_train_all_info();
			exit_enter();
			break;
		case 4: 
			system("clear");
			printf("请输入出发地：");
			char place_dep[10];
			scanf("%s", place_dep);
			find_train_info(find_place_dep, place_dep);
			exit_enter();
			break;
		case 5:
			system("clear");
			printf("请输入目的地：");
			char destination[30];
			scanf("%s", destination);
			find_train_info(find_destination, destination);
			exit_enter();
			break;
		default:
			break;
	}
}
/*
************************************************************************
* @brief      search_ticket()
* @param      void
* @return     void
* describe:   查找本人购票信息
************************************************************************
*/  
void search_ticket(void)
{
	struct list_head *pos1 = NULL;
	struct list_head *pos2 = NULL;
	kernel_list_node *customer = NULL;
	kernel_list_node *ticket = NULL;
	char temp[30];

	system("clear");

	printf("%s", ticket_buff);

	list_for_each(pos1, &customer_node)
	{
		customer = container_of(pos1, kernel_list_node, point_node);

		if( (!strcmp(customer->customer_data.num_id, buf)) ||\
			(!strcmp(customer->customer_data.phone_number, buf)))
		{
			strcpy(temp, customer->customer_data.num_id);
		}
	}
	list_for_each(pos2, &ticket_node)
	{
		ticket = container_of(pos2, kernel_list_node, point_node);

		if( !strcmp(ticket->ticket_data.num_id, temp) )
		{
			print_ticket_one_info(ticket);
		}
	}
}
/*
************************************************************************
* @brief      buy_ticket()
* @param      void
* @return     void
* describe:   购票
************************************************************************
*/  
void buy_ticket(void)
{
	char departure[20], destination[20], seat_num[10];
	int opt, buy_flag = 0;

	system("clear");
	printf("请输入出发地：");
	scanf("%s", departure);
	printf("请输入目的地：");
	scanf("%s", destination);

	struct list_head *pos1 = NULL;
	struct list_head *pos2 = NULL;
	kernel_list_node *train = NULL;
	kernel_list_node *customer = NULL;

	list_for_each(pos1, &train_node)
	{
		train = container_of(pos1, kernel_list_node, point_node);

		if( (!strcmp(train->train_data.place_dep, departure)) && (!strcmp(train->train_data.destination, destination)) )
		{
			
			printf("----------------------\n");
			printf("%s", train_buff);
			print_train_one_info(train);
			printf("请选择车票\n");
			printf("----------------------\n");
			printf("请输入座位：");
			scanf("%s", seat_num);
			printf("----------------------\n");
			printf("是否支付%d元\n", train->train_data.ticket_price);
			printf("1.是 2.否：");
			scanf("%d", &opt);
			if(opt == 1)
			{
				list_for_each(pos2, &customer_node)
				{
					customer = container_of(pos2, kernel_list_node, point_node);
					
					if( (!strcmp(customer->customer_data.num_id, buf)) ||\
						(!strcmp(customer->customer_data.phone_number, buf)))
					{
						customer->customer_data.balance -= train->train_data.ticket_price;
						inset_ticket_info(customer, train, seat_num);
						preserve_customer_info_file();
						buy_flag = 1;
					}
				}
			}
		}
	}
	if(buy_flag == 0)
		printf("当前没有该车次的票!!!!!!\n");
	else
		printf("购票成功!!!!!!\n");
}
/*
************************************************************************
* @brief      retreat_ticket()
* @param      void
* @return     void
* describe:   退票
************************************************************************
*/  
void retreat_ticket(fun_t handle)
{
	char train_name[10];
	int opt;
	system("clear");
	search_ticket();
	printf("----------------------\n");
	printf("请输入要退票的车次：");
	scanf("%s", train_name);

	int retreat_flag = 0;

	struct list_head *pos1 = NULL;
	struct list_head *pos2 = NULL;
	kernel_list_node *train = NULL;
	kernel_list_node *customer = NULL;

	list_for_each(pos1, &train_node)
	{
		train = container_of(pos1, kernel_list_node, point_node);
		if(handle(train, train_name) != NULL)
		{
			printf("退票需要收取车费百分之10手续费\n");
			printf("是否退票 1.是 2.否: ");
			scanf("%d", &opt);

			if(opt == 1)
			{
				list_for_each(pos2, &customer_node)
				{
					customer = container_of(pos2, kernel_list_node, point_node);
					
					if( (!strcmp(customer->customer_data.num_id, buf)) ||\
						(!strcmp(customer->customer_data.phone_number, buf)))
					{
						customer->customer_data.balance += (train->train_data.ticket_price*0.9);
						delete_ticket_info(train_name);
						preserve_customer_info_file();
						retreat_flag = 1;
					}
				}
			}
		}
	}	
	if(retreat_flag == 0)
		printf("退票失败!!!!!!\n");
	else
		printf("退票成功!!!!!!\n");
}
/*
************************************************************************
* @brief      wallet()
* @param      void
* @return     void
* describe:   钱包充值和提现
************************************************************************
*/  
void wallet(void)
{
	system("clear");
	user_money();

	double temp;

	switch (opt10)
	{
		case 1:
			system("clear");
			find_customer_balance(buf);
			printf("请输入要充值的金额：");
			scanf("%lf", &temp);
			revise_user_info(revise_add_balance, &temp, buf);
			printf("充值成功\n");
			exit_enter();
			break;
		case 2:
			system("clear");
			find_customer_balance(buf);
			printf("请输入要提现的金额：");
			scanf("%lf", &temp);
			revise_user_info(revise_reduce_balance, &temp, buf);
			printf("提现成功\n");
			exit_enter();
			break;
		case 3:
			system("clear");
			find_customer_balance(buf);
			exit_enter();
			break;
		default:
			break;
	}
}
/*
************************************************************************
* @brief      find_customer_balance()
* @param      void
* @return     void
* describe:   查询用户自己余额
************************************************************************
*/  
void find_customer_balance(void *arg)
{
	int find_flag = 0;

	struct list_head *pos = NULL;
	kernel_list_node *customer = NULL;

	list_for_each(pos, &customer_node)
	{
		customer = container_of(pos, kernel_list_node, point_node);

		if( (!strcmp(customer->customer_data.num_id, arg) ) ||\
			(!strcmp(customer->customer_data.phone_number, arg) ) )
		{
			printf("当前余额为：");
			printf("%.2lf元\n", customer->customer_data.balance);
		}
	}	
}
/*
************************************************************************
* @brief      revise_user_passwd()
* @param      void
* @return     void
* describe:   忘记密码并进行修改
************************************************************************
*/  
void revise_user_passwd(void)
{
	char user_name[20]; 
	system("clear");
	printf("请输入电话号码或者手机号: ");
	scanf("%s", user_name);
	revise_user_info(revise_passwd, NULL, user_name); 
	printf("修改成功\n");
	exit_enter(); 
}
/*
************************************************************************
* @brief      exit_enter()
* @param      void
* @return     void
* describe:   回车键退出
************************************************************************
*/  
void exit_enter(void)
{
	printf("----------------------\n");
	printf("\n");
	printf("按回车键退出");
	getchar();
	getchar();
}

