#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//数组方式实现环形队列，循环队列
typedef struct CircularQueue
{
	int* a;
	int front;
	int tail;
	int k;
}CircularQueue;

CircularQueue* CircularQueueCreat(int k);//创建循环队列并初始化
bool CircularQueuePush(CircularQueue* obj, int val);//入数据是否成功
bool CircularQueuePop(CircularQueue* obj);//出数据是否成功
int CircularQueueFront(CircularQueue* obj);//队头数据
int CircularQueueBack(CircularQueue* obj);//队尾数据
bool CircularQueueEmpty(CircularQueue* obj);//判空
bool CircularQueueFull(CircularQueue* obj);//判满
void CircularQueueFree(CircularQueue* obj);//释放
