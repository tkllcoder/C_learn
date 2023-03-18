#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//初始化
ListNode* ListNodeInit(ListNode* phead)
{
	//给一个哨兵位头节点并初始化
	phead = (ListNode*)malloc(sizeof(ListNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//申请新节点
ListNode* ListGetNewNode(ListDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->val = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

//尾插
void ListPushBack(ListNode* phead, ListDataType x)
{
	//phead->prev尾节点的下一个指向新节点 新节点的前一个节点指向，
	//新节点为尾下一个指向头节点，头节点的前指向尾节点
	/*ListNode* newNode = ListGetNewNode(x);

	phead->prev->next = newNode;
	newNode->prev = phead->prev;
	newNode->next = phead;
	phead->prev = newNode;*/
	ListInsert(phead, phead , x);
	
}

//双向带头循环链表打印
void ListNodePrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		printf("%d<->%d ", cur->val, cur->next->val);
		cur = cur->next;
	}
	printf("\n");
}

//尾删
void ListPopBack(ListNode* phead)
{
	/*assert(phead->next != phead);
	ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	free(tail);
	tail = phead->prev;
	tail->next = phead;*/
	ListErase(phead, phead->prev);
}

//头插
void ListPushFront(ListNode* phead, ListDataType x)
{
	//ListNode* newNode = ListGetNewNode(x);

	////头插
	//newNode->next = phead->next;
	//phead->next->prev = newNode;
	//phead->next = newNode;
	//newNode->prev = phead;
	ListInsert(phead, phead->next, x);
}

//头删
void ListPopFront(ListNode* phead)
{
	/*assert(phead->next != phead);
	ListNode* FirstNode = phead->next;
	phead->next = FirstNode->next;
	FirstNode->next->prev = phead;
	free(FirstNode);
	FirstNode = NULL;*/
	ListErase(phead, phead->next);
}

//找数据返回节点地址
ListNode* ListNodeFind(ListNode* phead, ListDataType x)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//某个位置前面插入一个节点 复用到头插和尾插
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x)
{
	ListNode* posPrev = pos->prev;

	ListNode* newNode = ListGetNewNode(x);

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;

}

//删除某个位置的节点 复用到头删和尾删
void ListErase(ListNode* phead, ListNode* pos)
{
	assert(phead->next != phead);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	pos = NULL;

	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//链表销毁
void ListDestroy(ListNode** pphead)
{
	ListNode* cur = (*pphead)->next;
	ListNode* next = cur->next;

	while (cur != *pphead)
	{
		free(cur);
		cur = next;
		next = cur->next;
	}
	free(*pphead);
	*pphead = NULL;
}




