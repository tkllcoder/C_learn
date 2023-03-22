#define _CRT_SECURE_NO_WARNINGS 1
#include"CircularQueue.h"

void CircularQueueTest()
{
	CircularQueue* cq = CircularQueueCreat(4);

	bool ret = CircularQueuePush(cq, 1);
	ret = CircularQueuePush(cq, 2);
	ret = CircularQueuePush(cq, 3);
	ret = CircularQueuePush(cq, 4);

	ret = CircularQueuePop(cq);

	ret = CircularQueuePush(cq, 5);


	ret = CircularQueuePop(cq);

	int front = CircularQueueFront(cq);
	int back = CircularQueueBack(cq);

	CircularQueueFree(cq);
}

int main()
{
	CircularQueueTest();
	return 0;
}