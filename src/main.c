/*
************************************************************************
* file name: main.c
* author: 苏尚宇
* date: Sat Nov 19 10:41:34 CST 2022
* path: /mnt/e/Data/yueq/work/purchasing_management_system
* describe: NULL
************************************************************************
*/

#include <stdio.h>
#include "main.h"
#include "kernel_list.h"
#include "system.h"
#include "callback.h"
#include "lawful.h"
#include "display.h"

int main(int argc, char *argv[])
{
	/* 初始化信息链表 */
	INIT_LIST_HEAD(&train_node);
	INIT_LIST_HEAD(&ticket_node);
	INIT_LIST_HEAD(&customer_node);

	proc(); // 登录界面

	/* 读取文件信息 */
	read_file_train_info();
	read_file_ticket_info();
	read_file_customer_info();
	
	while (1)
	{
		main_control(); // 总控制函数
	}
	
	return 0;
}
