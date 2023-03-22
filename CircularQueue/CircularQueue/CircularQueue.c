#define _CRT_SECURE_NO_WARNINGS 1
#include"CircularQueue.h"

//����ѭ�����в���ʼ��
CircularQueue* CircularQueueCreat(int k)
{
	CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
	assert(cq);
	cq->a = (int*)malloc(sizeof(int) * (k + 1));//��Ҫ��k�����뿪��k+1���ռ�
	cq->front = cq->tail = 0;
	cq->k = k;
	return cq;
}

//�������Ƿ�ɹ�
bool CircularQueuePush(CircularQueue* obj, int val)
{
	//���������������������ʧ��
	if (CircularQueueFull(obj))
	{
		return false;
	}
	//û���������ݣ��ı�β�±�
	obj->a[obj->tail] = val;
	obj->tail++;
	obj->tail %= (obj->k + 1);//�±굽β��ת
	return true;
}

//�������Ƿ�ɹ�
bool CircularQueuePop(CircularQueue* obj)
{
	//����գ��������ʧ��
	if (CircularQueueEmpty(obj))
	{
		return false;
	}
	//û��������ݸı�ͷ�±�
	obj->front++;
	obj->front %= (obj->k + 1);
	return true;
}

//��ͷ����
int CircularQueueFront(CircularQueue* obj)
{
	if (CircularQueueEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}

//��β����
int CircularQueueBack(CircularQueue* obj)
{
	if (CircularQueueEmpty(obj))
	{
		return -1;
	}
	if (obj->tail == 0)//��ת����
	{
		return obj->a[obj->k];
	}
	return obj->a[obj->tail - 1];
}

//�п�
bool CircularQueueEmpty(CircularQueue* obj)
{
	return obj->front == obj->tail;
}

//����
bool CircularQueueFull(CircularQueue* obj)
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

//�ͷ�
void CircularQueueFree(CircularQueue* obj)
{
	free(obj->a);
	obj->front = 0;
	obj->tail = 0;
	free(obj);
}