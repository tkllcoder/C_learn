#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

//栈初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//最开始top=0代表指向栈顶元素的下一位置，
	//top=-1表示指向栈顶元素
	ps->capacity = 0;
}

//栈销毁
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//判断容量
	if (ps->top == ps->capacity)
	{
		//获取新的容量
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

//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//有数据可删
	ps->top--;//删除数据变下标即可
}

//访问栈顶数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//栈非空

	return ps->a[ps->top - 1];
}

//查看栈数据个数
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//判断栈是否为空 为空返回真，非空返回假
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}

//判断括号匹配
bool IsValid(ST* ps, char a[])
{
	assert(ps);
	int i = 0;

	while (a[i] != '\0')
	{
		//1.判断为左括号入栈
		if (a[i] == '(' || a[i] == '[' || a[i] == '{')
		{
			StackPush(ps, a[i]);
		}
		//2.判断为右括号 出栈一个数据 并与右括号进行匹配，若不成功说明匹配失败
		else
		{
			//如果栈空 返回false
			if (StackEmpty(ps))
			{
				return false;
			}
			STDataType tmp = StackTop(ps);//访问栈顶数据
			StackPop(ps);//出栈
			if ((tmp == '(' && a[i] != ')') || ((tmp == '[' && a[i] != ']')) || ((tmp == '{' && a[i] != '}')))
			{
				return false;
			}
		}

		i++;
	}
	//3.判断栈是否为空，若为空则匹配完成，否则匹配失败
	bool ret = StackEmpty(ps);
	return ret;
}

//两个栈实现队列的功能
//两个栈创建队列并初始化
MyQueue* MyQueueCreat()
{
	MyQueue* st = (MyQueue*)malloc(sizeof(MyQueue));
	assert(st);
	StackInit(&st->s1);
	StackInit(&st->s2);
	return st;
}

//入数据
void MyQueuePush(MyQueue* obj, int x)
{
	//把栈1作为入数据的栈 栈2作为出数据的栈
	StackPush(&obj->s1, x);
}

//出数据 并返回出的数据
int MyQueuePop(MyQueue* obj)
{
	int front = 0;
	//判断 栈2非空 直接出数据
	if (!(StackEmpty(&obj->s2)))
	{
		front = StackTop(&obj->s2);
		StackPop(&obj->s2);
	}
	//否则将栈1的数据全部挪到栈2 再出数据
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

//得到队头数据
int MyQueuePeek(MyQueue* obj)
{
	int front = 0;
	//如果为空，倒一下
	if (StackEmpty(&obj->s2))
	{
		while (StackSize(&obj->s1) > 0)
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	//直接取得
	front = StackTop(&obj->s2);
	return front;
}

//判断队列是否为空
bool MyQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

//释放
void MyQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
}


