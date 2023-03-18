#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//��ʼ��
ListNode* ListNodeInit(ListNode* phead)
{
	//��һ���ڱ�λͷ�ڵ㲢��ʼ��
	phead = (ListNode*)malloc(sizeof(ListNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//�����½ڵ�
ListNode* ListGetNewNode(ListDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->val = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

//β��
void ListPushBack(ListNode* phead, ListDataType x)
{
	//phead->prevβ�ڵ����һ��ָ���½ڵ� �½ڵ��ǰһ���ڵ�ָ��
	//�½ڵ�Ϊβ��һ��ָ��ͷ�ڵ㣬ͷ�ڵ��ǰָ��β�ڵ�
	/*ListNode* newNode = ListGetNewNode(x);

	phead->prev->next = newNode;
	newNode->prev = phead->prev;
	newNode->next = phead;
	phead->prev = newNode;*/
	ListInsert(phead, phead , x);
	
}

//˫���ͷѭ�������ӡ
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

//βɾ
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

//ͷ��
void ListPushFront(ListNode* phead, ListDataType x)
{
	//ListNode* newNode = ListGetNewNode(x);

	////ͷ��
	//newNode->next = phead->next;
	//phead->next->prev = newNode;
	//phead->next = newNode;
	//newNode->prev = phead;
	ListInsert(phead, phead->next, x);
}

//ͷɾ
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

//�����ݷ��ؽڵ��ַ
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

//ĳ��λ��ǰ�����һ���ڵ� ���õ�ͷ���β��
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x)
{
	ListNode* posPrev = pos->prev;

	ListNode* newNode = ListGetNewNode(x);

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;

}

//ɾ��ĳ��λ�õĽڵ� ���õ�ͷɾ��βɾ
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

//��������
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




