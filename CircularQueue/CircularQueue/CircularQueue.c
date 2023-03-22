#define _CRT_SECURE_NO_WARNINGS 1
#include"CircularQueue.h"

//创建循环队列并初始化
CircularQueue* CircularQueueCreat(int k)
{
	CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
	assert(cq);
	cq->a = (int*)malloc(sizeof(int) * (k + 1));//想要存k个必须开辟k+1个空间
	cq->front = cq->tail = 0;
	cq->k = k;
	return cq;
}

//入数据是否成功
bool CircularQueuePush(CircularQueue* obj, int val)
{
	//如果队列已满，则入数据失败
	if (CircularQueueFull(obj))
	{
		return false;
	}
	//没满则入数据，改变尾下标
	obj->a[obj->tail] = val;
	obj->tail++;
	obj->tail %= (obj->k + 1);//下标到尾跳转
	return true;
}

//出数据是否成功
bool CircularQueuePop(CircularQueue* obj)
{
	//如果空，则出数据失败
	if (CircularQueueEmpty(obj))
	{
		return false;
	}
	//没空则出数据改变头下标
	obj->front++;
	obj->front %= (obj->k + 1);
	return true;
}

//队头数据
int CircularQueueFront(CircularQueue* obj)
{
	if (CircularQueueEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}

//队尾数据
int CircularQueueBack(CircularQueue* obj)
{
	if (CircularQueueEmpty(obj))
	{
		return -1;
	}
	if (obj->tail == 0)//跳转过的
	{
		return obj->a[obj->k];
	}
	return obj->a[obj->tail - 1];
}

//判空
bool CircularQueueEmpty(CircularQueue* obj)
{
	return obj->front == obj->tail;
}

//判满
bool CircularQueueFull(CircularQueue* obj)
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

//释放
void CircularQueueFree(CircularQueue* obj)
{
	free(obj->a);
	obj->front = 0;
	obj->tail = 0;
	free(obj);
}