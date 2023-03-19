#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include"Queue.h"

void StackTest()
{
	//判断括号是否匹配
	/*ST st;
	StackInit(&st);
	char s[] = "[]{}{([])}(";

	bool ret = IsValid(&st, s);
	if (ret == true)
	{
		printf("successful!\n");
	}
	else
	{
		printf("failed\n");
	}*/

	//栈测试
	//StackPush(&st, 1);
	//StackPush(&st, 2);
	//StackPush(&st, 3);
	//StackPush(&st, 4);
	//StackPush(&st, 5);

	//StackPop(&st);
	//StackPop(&st);
	//StackPop(&st);

	//printf("%d\n", StackTop(&st));
	//printf("%d\n", StackSize(&st));
	// 
	//遍历

	//StackDestroy(&st);//要注意释放内存，防止内存泄露

	//栈实现队列
	MyQueue* st = MyQueueCreat();

	MyQueuePush(st, 1);
	MyQueuePush(st, 2);
	MyQueuePush(st, 3);
	MyQueuePush(st, 4);

	int ret = MyQueuePop(st);
	int ret1 = MyQueuePeek(st);

	MyQueueFree(st);

}

void QueueTest()
{
	//队列测试
	//Queue q;
	//QueueInit(&q);

	//QueuePush(&q, 1);
	//QueuePush(&q, 2);
	//QueuePush(&q, 3);
	//QueuePush(&q, 4);

	//QueuePop(&q);
	//QueuePop(&q);

	//QDataType ret1 = QueueFront(&q);
	//QDataType ret2 = QueueBack(&q);
	//int ret3 = QueueSize(&q);

	//遍历

	//QueueDestroy(&q);
	
	//队列实现栈
	MyStack* st = MyStackCreat();

	MyStackPush(st, 1);
	MyStackPush(st, 2);
	MyStackPush(st, 3);
	MyStackPush(st, 4);

	int top = MyStackPop(st);
	int top1 = MyStackTop(st);

	MyStackFree(st);

}


int main()
{
	StackTest();
	//QueueTest();
	return 0;
}
