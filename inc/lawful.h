/*
************************************************************************
* file name: lawful.h
* author: 苏尚宇
* date: Sat Nov 19 17:19:33 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#ifndef _LAWFUL_H__
#define _LAWFUL_H__
#include <stdbool.h>
// #include "main.h"
// #include "kernel_list.h"
// #include "info_list.h"
// #include "system.h"
// #include "display.h"

extern void if_gender(char str[]);
extern bool specific_date(char str[], int *year, int *month, int *day);
extern bool if_lawful(char str[]);
extern bool address(char str[], char region[]);
extern bool if_num(char str[]);
extern bool if_long(char str[]);
extern bool Judge(char str[]);

#endif
