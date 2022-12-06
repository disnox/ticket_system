/*
************************************************************************
* file name: system.h
* author: 苏尚宇
* date: Sat Nov 19 10:46:44 CST 2022
* path: /mnt/e/Data/yueq/work/purchasing_management_system
* describe: NULL
************************************************************************
*/

#ifndef _SYSTEM_H__
#define _SYSTEM_H__

#include "info_list.h"


extern int opt1, opt2, opt3, opt4, opt5, opt6, opt7;
extern int opt8, opt9, opt10, opt11, opt12, opt13;

/* 随机数种子函数 */
extern void rand_str(char *str);

/* 登录函数 */
extern void admin_login(void);
extern void user_login(void);

/* 控制逻辑函数 */
extern void main_control(void);
extern void admin_control(void);

extern void admin_train(void);
extern void admin_find(void);
extern void admin_revise(void);

extern void admin_user(void);
extern void admin_user_find(void);
extern void admin_user_ticket_find(void);
extern void admin_revise_user(void);

extern void user_control(void);
extern void user_find(void);
extern void search_ticket(void);
extern void buy_ticket(void);
extern void retreat_ticket(fun_t handle);
extern void wallet(void);
extern void find_customer_balance(void *arg);
extern void revise_user_passwd(void);

extern void exit_enter(void);



#endif
