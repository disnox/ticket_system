/*
************************************************************************
* file name: lawful.c
* author: 苏尚宇
* date: Sat Nov 19 17:19:25 CST 2022
* path: /mnt/e/Data/yueq/Code/purchasing_management_system
* describe: NULL
************************************************************************
*/

#include "lawful.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
************************************************************************
* @brief      if_gender()
* @param      str[]: 身份证号字符串
* @return     void
* describe:   判断身份证号的性别
************************************************************************
*/
void if_gender(char str[])
{
	if((str[16]-48)%2 == 0)
		printf("性别：女\n");
	else
		printf("性别：男\n");
}
/*
************************************************************************
* @brief      specific_date()
* @param      str[]: 身份证号字符串
* @param      year: 年 | month: 月 | day: 日
* @return     bool
* describe:   判断身份证号的具体日期
************************************************************************
*/
bool specific_date(char str[], int *year, int *month, int *day)
{	
	int i;
	int a=1000, b=10, c=10;
	for(i = 6; i<10; i++)
	{		
		*year+= (str[i]-48)*a;
		a/=10;
	}
	for(i = 10; i<12; i++)
	{		
		*month+= (str[i]-48)*b;
		b/=10;
	}	
	for(i = 12; i<14; i++)
	{		
		*day+= (str[i]-48)*c;
		c/=10;
	}
	if(*month > 12)
	{
		return false;
	}
	else
		if((*year%4==0 && *year%100!=0) || *year%400==0)
		{
			if(*month == 2)
				if(*day > 29)
					return false;
			else
				if(*month == 1||*month == 3||*month == 5||*month == 7||*month == 8||*month == 10||*month == 12)
				{
					if(*day > 31)
						return false;
				}
				else
					if(*day > 30)
						return false;
		}
		else
			if(*month == 2)
				if(*day > 28)
					return false;
			else
				if(*month == 1||*month == 3||*month == 5||*month == 7||*month == 8||*month == 10||*month == 12)
				{
					if(*day > 31)
						return false;
				}
				else
					if(*day > 30)
						return false;		
	return true;
}

/*
************************************************************************
* @brief      if_lawful()
* @param      str[]: 身份证号字符串
* @return     bool
* describe:   判断身份证号是否合法
************************************************************************
*/
bool if_lawful(char str[])
{
	char region[128];
	int year = 0;
	int month = 0;
	int day = 0;
	// 1.位数是18位
	if(if_long(str) != true)
	{
		return false;
	}
	else
	// 2.前17位的字符必须是数字字符；第18位必须是0-9或者x
		if(if_num(str) != true)
		{
			return false;
		}
	
	// 3.前0~5位，必须是合法的地址码《地区码.txt》
	if(address(str, region) == false)
	{
		return false;
	}
	else
	{
		printf("地区：%s\n", region);
	}
	// 4.第6~13位获取生日信息，判断是否合法
	if(specific_date(str, &year, &month, &day))
	{
		printf("生日：%d年%d月%d日\n", year, month, day);
	}
	else
	{
		return false;
	}
	// 5.第14~16位，不用判断合法，可以通过最后一位得到性别信息
	if_gender(str);
	// 6.第17位是检验码。
	if(Judge(str) == false)
	{
		return false;
	}
	else		
		return true;
}
/*
************************************************************************
* @brief      address()
* @param      str[]: 身份证号字符串 | region: 地区区号
* @return     bool
* describe:   判断身份证属于那个地区
************************************************************************
*/
bool address(char str[], char region[])
{
	long int Guangxi[] =	{450100,450103,450102,450105,450107,450108,450109,450110,450181,450123,450124,450125,450126};
	char *Guangxi_region[] = {"南宁市","青秀区","兴宁区","江南区","西乡塘区","良庆区","邕宁区","武鸣区","横洲市","隆安县","马山县","上林县","宾阳县"};
	char *name = malloc(sizeof(char));
	char ch[6] = {0};
	strncpy(ch, str, 6);
	long int region_num = atoi(ch);
	for(int i=0; i<40; i++)
	{
		if(region_num == Guangxi[i])
		{
			sprintf(region, "%s%s", "广西", Guangxi_region[i]);
		}
	}
	if(strlen(region)==0)
		return false;
	else
		return true;
	
}
/*
************************************************************************
* @brief      if_num()
* @param      str[]: 身份证号字符串
* @return     bool
* describe:   判断身份证号的数字是否合法
************************************************************************
*/
bool if_num(char str[])   
{      
	int flag = 0;                   
	for(int i=0; i<17; i++)
	{                     
		if((str[i]-48)>'9' && (str[i]-48) <'0')
			flag = 1;
	}
	if(flag == 0)
		return true;
	else
		return false;
}                         
/*
************************************************************************
* @brief      if_long()
* @param      str[]: 身份证号字符串
* @return     bool
* describe:   判断身份证号是否是18位
************************************************************************
*/                         
bool if_long(char str[])  
{                         
	if(strlen(str) == 18) 
		return true;     
	else
		return false;
}
/*
************************************************************************
* @brief      if_long()
* @param      str[]: 身份证号字符串
* @return     bool
* describe:   判断身份证号最后一位
************************************************************************
*/    
bool Judge(char str[])
{
	int i;
	int num = 0;
	int age = 0;
	int flag = 0;
	//5 0 0  2 4 0 1 9 9 6 0 5 0  2 1 1 7 2
	//7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2
	int m[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	for(i = 0; i<17; i++)
	{
		num+=(str[i]-48)*m[i];
	}	
	age = num%11;
	switch(age)
	{
		case 0:if(str[17] == '1') flag = 1;break;
		case 1:if(str[17] == '0') flag = 1;break;
		case 2:if(str[17] == 'X') flag = 1;break;
		case 3:if(str[17] == '9') flag = 1;break;
		case 4:if(str[17] == '8') flag = 1;break;
		case 5:if(str[17] == '7') flag = 1;break;
		case 6:if(str[17] == '6') flag = 1;break;
		case 7:if(str[17] == '5') flag = 1;break;
		case 8:if(str[17] == '4') flag = 1;break;
		case 9:if(str[17] == '3') flag = 1;break;
		case 10:if(str[17] == '2') flag = 1;break;	
	}
	if(flag == 1)
		return true;
	else
		return false;
}

