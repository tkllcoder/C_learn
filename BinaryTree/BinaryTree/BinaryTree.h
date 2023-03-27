#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include"Queue.h"

//�������ı���
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//����
	struct BinaryTreeNode* right;//���ֵ�
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root);//ǰ�����
void InOrder(BTNode* root);//�������
void PostOrder(BTNode* root);//�������
int TreeSize(BTNode* root);//�ڵ����
int TreeLeafSize(BTNode* root);//Ҷ�ӽڵ����
void LevelOrder(BTNode* root);//�������
char* PrevOrder1(BTNode* root, int* returnSize);//ǰ��������������鼰�����С
int TreeDeep(BTNode* root);//�������
bool IsBalanced(BTNode* root);//�ж�һ�ö������Ƿ�Ϊ�߶�ƽ��Ķ�����
void TreeDestroy(BTNode* root);//������

