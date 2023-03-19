#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char STDataType;

typedef struct stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;
}ST;

//�ӿں���
void StackInit(ST* ps);//ջ��ʼ��
void StackDestroy(ST* ps);//ջ����
void StackPush(ST* ps, STDataType x);//��ջ
void StackPop(ST* ps);//��ջ
STDataType StackTop(ST* ps);//����ջ������
int StackSize(ST* ps);//�鿴ջ���ݸ���
bool StackEmpty(ST* ps);//�ж�ջ�Ƿ�Ϊ��
bool IsValid(ST* ps, char a[]);//�ж�����ƥ��

//����ջʵ�ֶ��еĹ���
typedef struct MyQueue
{
	ST s1;
	ST s2;
}MyQueue;

MyQueue* MyQueueCreat();//����ջ�������в���ʼ��
void MyQueuePush(MyQueue* obj, int x);//������
int MyQueuePop(MyQueue* obj);//������
int MyQueuePeek(MyQueue* obj);//�õ���ͷ����
bool MyQueueEmpty(MyQueue* obj);//�ж϶����Ƿ�Ϊ��
void MyQueueFree(MyQueue* obj);//�ͷ�
