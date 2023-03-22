#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//���鷽ʽʵ�ֻ��ζ��У�ѭ������
typedef struct CircularQueue
{
	int* a;
	int front;
	int tail;
	int k;
}CircularQueue;

CircularQueue* CircularQueueCreat(int k);//����ѭ�����в���ʼ��
bool CircularQueuePush(CircularQueue* obj, int val);//�������Ƿ�ɹ�
bool CircularQueuePop(CircularQueue* obj);//�������Ƿ�ɹ�
int CircularQueueFront(CircularQueue* obj);//��ͷ����
int CircularQueueBack(CircularQueue* obj);//��β����
bool CircularQueueEmpty(CircularQueue* obj);//�п�
bool CircularQueueFull(CircularQueue* obj);//����
void CircularQueueFree(CircularQueue* obj);//�ͷ�
