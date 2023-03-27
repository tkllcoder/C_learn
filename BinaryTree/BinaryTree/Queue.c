#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//���г�ʼ��
void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
}

//��������
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

//��β������
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->val = x;
	newNode->next = NULL;

	//��һ�β�����
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

//��ͷɾ����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QueueNode* newHead = pq->head->next;
	free(pq->head);
	pq->head = newHead;
	if (pq->head == NULL)
	{
		pq->tail = NULL;//��ֹҰָ��
	}
}

//���ʶ�ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

//���ʶ�β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->val;
}

//�鿴���ݶ���
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

//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

/////��������ʵ��ջ
//ջ���� ��ʼ��
MyStack* MyStackCreat()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	assert(st);
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

//��Ԫ��xѹ��ջ
void MyStackPush(MyStack* pq, int x)
{
	//���ǿյ�����������
	if (!(QueueEmpty(&pq->q1)))
	{
		QueuePush(&pq->q1, x);
	}
	else
	{
		QueuePush(&pq->q2, x);
	}
}

//��ջ������ջ��Ԫ��
int MyStackPop(MyStack* pq)
{
	//�ж��ĸ�����Ϊ��
	Queue* emptyQ = &pq->q1;
	Queue* nonemptyQ = &pq->q2;
	if (!(QueueEmpty(&pq->q1)))
	{
		nonemptyQ = &pq->q1;
		emptyQ = &pq->q2;
	}
	//���ǿյ�����ʣ���һ�����ݴ����յĶ�����
	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));//���ǿտյĶ�ͷ�ŵ��յĶ�����
		QueuePop(nonemptyQ);//����
	}

	int top = QueueFront(nonemptyQ);//����ջ��Ԫ��
	QueuePop(nonemptyQ);
	return top;
}

//����ջ��Ԫ�� �ǿն��еĶ�β
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

//ջ�п�
bool MyStackEmpty(MyStack* pq)
{
	return QueueEmpty(&pq->q1) && QueueEmpty(&pq->q2);
}

//ջ�ͷ�
void MyStackFree(MyStack* pq)
{
	QueueDestroy(&pq->q1);
	QueueDestroy(&pq->q2);
	free(pq);
}