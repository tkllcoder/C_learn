#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListDataType;

typedef struct ListNode
{
	ListDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* ListNodeInit(ListNode* phead);//��ʼ��
ListNode* ListGetNewNode(ListDataType x);//�����½ڵ�
void ListPushBack(ListNode* phead, ListDataType x);//β��
void ListNodePrint(ListNode* phead);//˫���ͷѭ�������ӡ
void ListPopBack(ListNode* phead);//βɾ
void ListPushFront(ListNode* phead, ListDataType x);//ͷ��
void ListPopFront(ListNode* phead);//ͷɾ
ListNode* ListNodeFind(ListNode* phead, ListDataType x);//�����ݷ��ؽڵ��ַ
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x);//ĳ��λ��ǰ�����һ���ڵ�
void ListErase(ListNode* phead, ListNode* pos);//ɾ��ĳ��λ�õĽڵ�
void ListDestroy(ListNode** pphead);//�������٣�����ͷָ��ҲҪ�ÿգ�����Ҫ������ָ��
 

