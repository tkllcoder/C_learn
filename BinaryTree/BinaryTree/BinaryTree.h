#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include"Queue.h"

//二叉树的遍历
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//左孩子
	struct BinaryTreeNode* right;//右兄弟
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root);//前序遍历
void InOrder(BTNode* root);//中序遍历
void PostOrder(BTNode* root);//后序遍历
int TreeSize(BTNode* root);//节点个数
int TreeLeafSize(BTNode* root);//叶子节点个数
void LevelOrder(BTNode* root);//层序遍历
char* PrevOrder1(BTNode* root, int* returnSize);//前序遍历并返回数组及数组大小
int TreeDeep(BTNode* root);//树的深度
bool IsBalanced(BTNode* root);//判断一棵二叉树是否为高度平衡的二叉树
void TreeDestroy(BTNode* root);//树销毁

