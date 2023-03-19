#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

//ջ��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//�ʼtop=0����ָ��ջ��Ԫ�ص���һλ�ã�
	//top=-1��ʾָ��ջ��Ԫ��
	ps->capacity = 0;
}

//ջ����
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//�ж�����
	if (ps->top == ps->capacity)
	{
		//��ȡ�µ�����
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//�����ݿ�ɾ
	ps->top--;//ɾ�����ݱ��±꼴��
}

//����ջ������
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//ջ�ǿ�

	return ps->a[ps->top - 1];
}

//�鿴ջ���ݸ���
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//�ж�ջ�Ƿ�Ϊ�� Ϊ�շ����棬�ǿշ��ؼ�
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}

//�ж�����ƥ��
bool IsValid(ST* ps, char a[])
{
	assert(ps);
	int i = 0;

	while (a[i] != '\0')
	{
		//1.�ж�Ϊ��������ջ
		if (a[i] == '(' || a[i] == '[' || a[i] == '{')
		{
			StackPush(ps, a[i]);
		}
		//2.�ж�Ϊ������ ��ջһ������ ���������Ž���ƥ�䣬�����ɹ�˵��ƥ��ʧ��
		else
		{
			//���ջ�� ����false
			if (StackEmpty(ps))
			{
				return false;
			}
			STDataType tmp = StackTop(ps);//����ջ������
			StackPop(ps);//��ջ
			if ((tmp == '(' && a[i] != ')') || ((tmp == '[' && a[i] != ']')) || ((tmp == '{' && a[i] != '}')))
			{
				return false;
			}
		}

		i++;
	}
	//3.�ж�ջ�Ƿ�Ϊ�գ���Ϊ����ƥ����ɣ�����ƥ��ʧ��
	bool ret = StackEmpty(ps);
	return ret;
}

//����ջʵ�ֶ��еĹ���
//����ջ�������в���ʼ��
MyQueue* MyQueueCreat()
{
	MyQueue* st = (MyQueue*)malloc(sizeof(MyQueue));
	assert(st);
	StackInit(&st->s1);
	StackInit(&st->s2);
	return st;
}

//������
void MyQueuePush(MyQueue* obj, int x)
{
	//��ջ1��Ϊ�����ݵ�ջ ջ2��Ϊ�����ݵ�ջ
	StackPush(&obj->s1, x);
}

//������ �����س�������
int MyQueuePop(MyQueue* obj)
{
	int front = 0;
	//�ж� ջ2�ǿ� ֱ�ӳ�����
	if (!(StackEmpty(&obj->s2)))
	{
		front = StackTop(&obj->s2);
		StackPop(&obj->s2);
	}
	//����ջ1������ȫ��Ų��ջ2 �ٳ�����
	else
	{
		while (StackSize(&obj->s1) > 0)
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
		front = StackTop(&obj->s2);
		StackPop(&obj->s2);
	}
	return front;
}

//�õ���ͷ����
int MyQueuePeek(MyQueue* obj)
{
	int front = 0;
	//���Ϊ�գ���һ��
	if (StackEmpty(&obj->s2))
	{
		while (StackSize(&obj->s1) > 0)
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	//ֱ��ȡ��
	front = StackTop(&obj->s2);
	return front;
}

//�ж϶����Ƿ�Ϊ��
bool MyQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

//�ͷ�
void MyQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
}


