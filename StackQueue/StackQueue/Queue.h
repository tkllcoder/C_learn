#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

//节点结构
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QueueNode;

//头尾指针
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//接口函数
void QueueInit(Queue* pq);//队列初始化
void QueueDestroy(Queue* pq);//队列销毁
void QueuePush(Queue* pq, QDataType x);//队尾插数据
void QueuePop(Queue* pq);//对头删数据
QDataType QueueFront(Queue* pq);//访问队头数据
QDataType QueueBack(Queue* pq);//访问队尾数据
int QueueSize(Queue* pq);//查看数据多少
bool QueueEmpty(Queue* pq);//队列判空

//////用两个队列实现栈的功能
typedef struct MyStack
{
	Queue q1;
	Queue q2;
}MyStack;

MyStack* MyStackCreat();//栈创建
void MyStackPush(MyStack* pq, int x);//将元素x压入栈
int MyStackPop(MyStack* pq);//出栈并返回栈顶元素
int MyStackTop(MyStack* pq);//返回栈顶元素
bool MyStackEmpty(MyStack* pq);//栈判空
void MyStackFree(MyStack* pq);//栈释放