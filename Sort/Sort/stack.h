#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char STDataType;

typedef struct stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;
}ST;

//接口函数
void StackInit(ST* ps);//栈初始化
void StackDestroy(ST* ps);//栈销毁
void StackPush(ST* ps, STDataType x);//入栈
void StackPop(ST* ps);//出栈
STDataType StackTop(ST* ps);//访问栈顶数据
int StackSize(ST* ps);//查看栈数据个数
bool StackEmpty(ST* ps);//判断栈是否为空
bool IsValid(ST* ps, char a[]);//判断括号匹配

//两个栈实现队列的功能
typedef struct MyQueue
{
	ST s1;
	ST s2;
}MyQueue;

MyQueue* MyQueueCreat();//两个栈创建队列并初始化
void MyQueuePush(MyQueue* obj, int x);//入数据
int MyQueuePop(MyQueue* obj);//出数据
int MyQueuePeek(MyQueue* obj);//得到队头数据
bool MyQueueEmpty(MyQueue* obj);//判断队列是否为空
void MyQueueFree(MyQueue* obj);//释放
