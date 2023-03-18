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

ListNode* ListNodeInit(ListNode* phead);//初始化
ListNode* ListGetNewNode(ListDataType x);//申请新节点
void ListPushBack(ListNode* phead, ListDataType x);//尾插
void ListNodePrint(ListNode* phead);//双向带头循环链表打印
void ListPopBack(ListNode* phead);//尾删
void ListPushFront(ListNode* phead, ListDataType x);//头插
void ListPopFront(ListNode* phead);//头删
ListNode* ListNodeFind(ListNode* phead, ListDataType x);//找数据返回节点地址
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x);//某个位置前面插入一个节点
void ListErase(ListNode* phead, ListNode* pos);//删除某个位置的节点
void ListDestroy(ListNode** pphead);//链表销毁，由于头指针也要置空，所以要传二级指针
 

