#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

//�ڵ�ṹ
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QueueNode;

//ͷβָ��
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//�ӿں���
void QueueInit(Queue* pq);//���г�ʼ��
void QueueDestroy(Queue* pq);//��������
void QueuePush(Queue* pq, QDataType x);//��β������
void QueuePop(Queue* pq);//��ͷɾ����
QDataType QueueFront(Queue* pq);//���ʶ�ͷ����
QDataType QueueBack(Queue* pq);//���ʶ�β����
int QueueSize(Queue* pq);//�鿴���ݶ���
bool QueueEmpty(Queue* pq);//�����п�

//////����������ʵ��ջ�Ĺ���
typedef struct MyStack
{
	Queue q1;
	Queue q2;
}MyStack;

MyStack* MyStackCreat();//ջ����
void MyStackPush(MyStack* pq, int x);//��Ԫ��xѹ��ջ
int MyStackPop(MyStack* pq);//��ջ������ջ��Ԫ��
int MyStackTop(MyStack* pq);//����ջ��Ԫ��
bool MyStackEmpty(MyStack* pq);//ջ�п�
void MyStackFree(MyStack* pq);//ջ�ͷ�