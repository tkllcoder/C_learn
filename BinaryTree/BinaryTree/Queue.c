#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//队列初始化
void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
}

//队列销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

//队尾插数据
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->val = x;
	newNode->next = NULL;

	//第一次插数据
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}

//队头删数据
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QueueNode* newHead = pq->head->next;
	free(pq->head);
	pq->head = newHead;
	if (pq->head == NULL)
	{
		pq->tail = NULL;//防止野指针
	}
}

//访问队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

//访问队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->val;
}

//查看数据多少
int QueueSize(Queue* pq)
{
	assert(pq);

	int count = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

/////两个队列实现栈
//栈创建 初始化
MyStack* MyStackCreat()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	assert(st);
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

//将元素x压入栈
void MyStackPush(MyStack* pq, int x)
{
	//往非空的里面入数据
	if (!(QueueEmpty(&pq->q1)))
	{
		QueuePush(&pq->q1, x);
	}
	else
	{
		QueuePush(&pq->q2, x);
	}
}

//出栈并返回栈顶元素
int MyStackPop(MyStack* pq)
{
	//判断哪个队列为空
	Queue* emptyQ = &pq->q1;
	Queue* nonemptyQ = &pq->q2;
	if (!(QueueEmpty(&pq->q1)))
	{
		nonemptyQ = &pq->q1;
		emptyQ = &pq->q2;
	}
	//将非空的数据剩随后一个数据传到空的队列中
	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));//将非空空的队头放到空的队列中
		QueuePop(nonemptyQ);//出列
	}

	int top = QueueFront(nonemptyQ);//返回栈顶元素
	QueuePop(nonemptyQ);
	return top;
}

//返回栈顶元素 非空队列的队尾
int MyStackTop(MyStack* pq)
{
	if (!(QueueEmpty(&pq->q1)))
	{
		return QueueBack(&pq->q1);
	}
	else
	{
		return QueueBack(&pq->q2);
	}
}

//栈判空
bool MyStackEmpty(MyStack* pq)
{
	return QueueEmpty(&pq->q1) && QueueEmpty(&pq->q2);
}

//栈释放
void MyStackFree(MyStack* pq)
{
	QueueDestroy(&pq->q1);
	QueueDestroy(&pq->q2);
	free(pq);
}