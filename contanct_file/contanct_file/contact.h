#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELE 20
#define MAX_ADDR 20
#define MAX 3

//ͨѶ��
typedef struct contacter
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}contacter;

//ͨѶ¼
//typedef struct contactlist
//{
//	contacter contact_table[MAX];
//	int total;//��Ч��ϵ�˸���
//}contactlist;
//ͨѶ¼�ṹ�壬������ֵ����
typedef struct contactlist
{
	contacter* contact_table;//ͨѶ¼ָ��
	int total;//��Ч��ϵ�˸���
	int base;//�ռ����
}contactlist;

void InitContact(contactlist* pc);//��ʼ��ͨѶ¼
void LoadContact(contactlist* pc);//�����ϴ�ͨѶ¼��Ϣ
void CheckBody(contactlist* pc);//����ڴ��Ƿ��㹻����Ҫ����
void AddContact(contactlist* pc);//������ϵ��
void PrintContact(contactlist* pc);//��ʾͨѶ¼
void DelContact(contactlist* pc);//ɾ����ϵ��
void SearchContact(contactlist* pc);//������ϵ��
void ModifyContact(contactlist* pc);//�޸���ϵ��
void SortContact(contactlist* pc);//������ϵ��
void SaveContact(contactlist* pc);//����ͨѶ¼���ļ�
void ExitContact(contactlist* pc);//�˳������ͷ��ڴ��ָ��
