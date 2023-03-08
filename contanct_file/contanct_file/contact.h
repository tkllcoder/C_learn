#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELE 20
#define MAX_ADDR 20
#define MAX 3

//通讯人
typedef struct contacter
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}contacter;

//通讯录
//typedef struct contactlist
//{
//	contacter contact_table[MAX];
//	int total;//有效联系人个数
//}contactlist;
//通讯录结构体，用三个值代替
typedef struct contactlist
{
	contacter* contact_table;//通讯录指针
	int total;//有效联系人个数
	int base;//空间个数
}contactlist;

void InitContact(contactlist* pc);//初始化通讯录
void LoadContact(contactlist* pc);//加载上次通讯录信息
void CheckBody(contactlist* pc);//检查内存是否足够，需要增容
void AddContact(contactlist* pc);//增加联系人
void PrintContact(contactlist* pc);//显示通讯录
void DelContact(contactlist* pc);//删除联系人
void SearchContact(contactlist* pc);//查找联系人
void ModifyContact(contactlist* pc);//修改联系人
void SortContact(contactlist* pc);//排序联系人
void SaveContact(contactlist* pc);//保存通讯录到文件
void ExitContact(contactlist* pc);//退出程序，释放内存和指针
