#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void ListTest()
{
	ListNode* plist = NULL;
	plist = ListNodeInit(plist);

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListNodePrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListNodePrint(plist);

	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListNodePrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListNodePrint(plist);

	ListNode* pos = ListNodeFind(plist, 2);
	ListErase(plist, pos);
	ListNodePrint(plist);


	ListDestroy(&plist);
}

int main()
{
	ListTest();
	return 0;
}