#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"BinaryTree.h"


int main()
{
	//快速构建一个二叉树
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	F->data = 'F';
	F->left = NULL;
	F->right = NULL; 

	BTNode* G = (BTNode*)malloc(sizeof(BTNode));
	G->data = 'G';
	G->left = NULL;
	G->right = NULL;

	A->left = B;
	B->left = C;
	B->right = D;
	D->left = E;
	D->right = F;
	E->right = G;

	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");

	printf("size = %d\n", TreeSize(A));

	printf("size = %d\n", TreeLeafSize(D));

	//利用队列实现二叉树的层序遍历
	LevelOrder(A);

	//前序遍历并返回数组
	int size = 0;
	char* a = PrevOrder1(A, &size);

	int deep = TreeDeep(A);

	bool balance = IsBalanced(A);

	TreeDestroy(A);

	return 0;

}

