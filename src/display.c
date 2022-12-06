/*
************************************************************************
* file name: display.c
* author: 苏尚宇
* date: Wed Nov 23 09:59:08 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "display.h"
#include "system.h"

/*
************************************************************************
* @brief      proc()
* @param      void
* @return     void
* describe:   加载界面
************************************************************************
*/  
void proc(void)
{
	int i = 0;
	char buf[102];
	memset(buf, '\0', sizeof(buf));
	const char *la = "|/-\\";
	
	printf("\t\t\t\t\t正在进入客运购票系统\n");
	while(i<=100){
		printf("[%-100s][%d%%][%c]\r", buf, i, la[i%4]);
		fflush(stdout);
		buf[i] = '*';
		i++;
		usleep(10000);
	}
	printf("\n");
	printf("系统加载完毕，按回车键继续");
	getchar();
}
/*
************************************************************************
* @brief      menu_display()
* @param      void
* @return     void
* describe:   主菜单界面
************************************************************************
*/  
void menu_display(void)
{
	// 清屏操作
	system("clear");

	printf("----------------------\n");
	printf("|  客运购票管理系统  |\n");
	printf("----------------------\n");
	printf("| 1. 普通用户登录    |\n");
	printf("| 2. 管理员登录      |\n");
	printf("| 3. 新用户注册      |\n");
	printf("| 4. 忘记密码        |\n");
	printf("| 5. 退出            |\n");
	printf("----------------------\n");
}
/*
************************************************************************
* @brief      admin_display()
* @param      void
* @return     void
* describe:   管理员界面
************************************************************************
*/  
void admin_display(void)
{
	system("clear");
	printf("----------------------\n");
	printf("|     管理员系统     |\n");
	printf("----------------------\n");
	printf("| 1. 车次信息管理    |\n");
	printf("| 2. 注册用户管理    |\n");
	printf("| 3. 返回上一级菜单  |\n");
	printf("----------------------\n");
} 
/*
************************************************************************
* @brief      admin_train_display()
* @param      void
* @return     void
* describe:   管理员的车次信息管理界面
************************************************************************
*/  
void admin_train_display(void)
{	
	system("clear");
	printf("----------------------\n");
	printf("|    车次信息管理    |\n");
	printf("----------------------\n");
	printf("| 1. 新增车次信息    |\n");
	printf("| 2. 删除车次信息    |\n");
	printf("| 3. 查询车次信息    |\n");
	printf("| 4. 修改车次信息    |\n");
	printf("| 5. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt2);
}
/*
************************************************************************
* @brief      admin_train_find_display()
* @param      void
* @return     void
* describe:   管理员的车次信息管理的查找界面
************************************************************************
*/  
void admin_train_find_display(void)
{	
	system("clear");
	printf("----------------------\n");
	printf("|       信息索引     |\n");
	printf("----------------------\n");
	printf("| 1. 查询车次信息    |\n");
	printf("| 2. 查询车次售票信息|\n");
	printf("| 3. 查询车次发车时间|\n");
	printf("| 4. 按发车时间排序  |\n");
	printf("| 5. 按票数排序      |\n");
	printf("| 6. 按票价排序      |\n");
	printf("| 7. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt4);
}
/*
************************************************************************
* @brief      admin_train_revise_display()
* @param      void
* @return     void
* describe:   管理员的车次信息管理的修改信息界面
************************************************************************
*/  
void admin_train_revise_display(void)
{	
	system("clear");
	printf("----------------------\n");
	printf("|      信息修改      |\n");
	printf("----------------------\n");
	printf("| 1. 修改出发地      |\n");
	printf("| 2. 修改目的地      |\n");
	printf("| 3. 修改发车时间    |\n");
	printf("| 4. 修改行程时间    |\n");
	printf("| 5. 修改票价        |\n");
	printf("| 6. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt5);
}
/*
************************************************************************
* @brief      admin_user_display()
* @param      void
* @return     void
* describe:   管理员的用户信息管理界面
************************************************************************
*/  
void admin_user_display(void)
{	
	system("clear");
	printf("----------------------\n");
	printf("|    用户信息管理    |\n");
	printf("----------------------\n");
	printf("| 1. 新增用户信息    |\n");
	printf("| 2. 删除用户信息    |\n");
	printf("| 3. 查询用户信息    |\n");
	printf("| 4. 查询用户购票信息|\n"); 
	printf("| 5. 修改用户信息    |\n");
	printf("| 6. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt3);
}
/*
************************************************************************
* @brief      admin_find_display()
* @param      void
* @return     void
* describe:   管理员的用户信息管理界面的查找界面
************************************************************************
*/  
void admin_find_display(void)
{	
	system("clear");
	printf("----------------------\n");
	printf("|      信息索引      |\n");
	printf("----------------------\n");
	printf("| 1. 按姓名查找      |\n");
	printf("| 2. 按身份证号查找  |\n");
	printf("| 3. 按用户ID查找    |\n");
	printf("| 4. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt6);
}
/*
************************************************************************
* @brief      admin_user_revise_display()
* @param      void
* @return     void
* describe:   管理员的用户信息管理界面的修改用户信息界面
************************************************************************
*/  
void admin_user_revise_display(void)
{	
	system("clear");
	printf("----------------------\n");
	printf("|      信息修改      |\n");
	printf("----------------------\n");
	printf("| 1. 修改车次        |\n");
	printf("| 2. 修改座位        |\n");
	printf("| 3. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt7);
}
/*
************************************************************************
* @brief      user_display()
* @param      void
* @return     void
* describe:   用户界面
************************************************************************
*/  
void user_display(void)
{
	system("clear");
	printf("----------------------\n");
	printf("|      用户系统      |\n");
	printf("----------------------\n");
	printf("| 1. 查询客运信息    |\n");
	printf("| 2. 查看购票信息    |\n");
	printf("| 3. 购票            |\n");
	printf("| 4. 退票            |\n");
	printf("| 5. 钱包            |\n");
	printf("| 6. 修改密码        |\n");
	printf("| 7. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt8);
} 
/*
************************************************************************
* @brief      user_find_display()
* @param      void
* @return     void
* describe:   用户查找信息界面
************************************************************************
*/  
void user_find_display(void)
{
	system("clear");
	printf("----------------------\n");
	printf("|      信息索引      |\n");
	printf("----------------------\n");
	printf("| 1. 发车时间        |\n");
	printf("| 2. 余票            |\n");
	printf("| 3. 票价            |\n");
	printf("| 4. 选择出发地      |\n");
	printf("| 5. 选择目的地      |\n");
	printf("| 6. 返回上一级菜单  |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt9);
} 
/*
************************************************************************
* @brief      user_find_display()
* @param      void
* @return     void
* describe:   用户钱包界面
************************************************************************
*/  
void user_money(void)
{
	system("clear");
	printf("----------------------\n");
	printf("|         钱包        |\n");
	printf("----------------------\n");
	printf("| 1. 充值            |\n");
	printf("| 2. 提现            |\n");
	printf("| 3. 余额            |\n");
	printf("| 4. 返回上一级菜单   |\n");
	printf("----------------------\n");
	printf("请选择你的操作：");
	scanf("%d", &opt10);
} 
