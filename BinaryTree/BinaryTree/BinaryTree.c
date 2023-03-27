#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//ǰ����� ��������������������������������������������������������������
//�ݹ���ã������㷨  �������� ע��ݹ���õ���ںͷ��ؼ������ĳ���
void PrevOrder(BTNode* root)
{
	//��������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);//��
	PrevOrder(root->left);//�������ݹ�
	PrevOrder(root->right);//�������ݹ�
}

//�������
void InOrder(BTNode* root)
{
	//��������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);//�������ݹ�
	printf("%c ", root->data);//��
	InOrder(root->right);//�������ݹ�
}

//�������
void PostOrder(BTNode* root)
{
	//��������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);//�������ݹ�
	PostOrder(root->right);//�������ݹ�
	printf("%c ", root->data);//��
}

//�ڵ���� ͬ���ǵݹ����
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

//Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//������� ˼���ö�����ʵ��
void LevelOrder(BTNode* root)
{
	//������в���ʼ��
	Queue q;
	QueueInit(&q);

	//1.�����ڵ����
	QueuePush(&q, root);
	//ѭ��:���в�Ϊ�� 2.һ���ڵ���� 3.�ٽ����ӽڵ�����Һ�����ӣ�Ϊ�����롣
	while (!(QueueEmpty(&q)))
	{
		BTNode* cur = QueueFront(&q);
		printf("%c ", cur->data);
		QueuePop(&q);
		if (cur->left != NULL)
		{
			QueuePush(&q, cur->left);
		}
		if (cur->right != NULL)
		{
			QueuePush(&q, cur->right);
		}
	}
	QueueDestroy(&q);
}

//ǰ��������������鼰�����С
void PrevOrder10(BTNode* root, char* a, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	a[(*pi)] = root->data;
	(*pi)++;
	PrevOrder10(root->left, a, pi);
	PrevOrder10(root->right, a, pi);
}
char* PrevOrder1(BTNode* root, int* returnSize)
{
	//�ڵ���� �����ٿռ䷵��
	int size = TreeSize(root);
	char* a = (char*)malloc(sizeof(char) * size);
	*returnSize = size;

	int i = 0;
	//������ڵ�ͳ�ʼ�±꣬����ǰ�������ȡ����Ԫ��
	PrevOrder10(root, a, &i);
	return a;
}

//�������  ��Ȼ����˼��ݹ� �������������������������ȵ����ֵ����1
int TreeDeep(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDeep = TreeDeep(root->left);
	int rightDeep = TreeDeep(root->right);

	return leftDeep > rightDeep ? (leftDeep + 1) : (rightDeep + 1);

}

//�ж�һ�ö������Ƿ�Ϊ�߶�ƽ��Ķ�����  ÿ���ڵ�������߶Ȳ�ľ���ֵ������1
bool IsBalanced(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int deepL = TreeDeep(root->left);
	int deepR = TreeDeep(root->right);
	
	return abs(deepL - deepR) < 2 && IsBalanced(root->left) && IsBalanced(root->right);
	//�ж��Լ��ڵ㣬�������Ƿ�ƽ�⣬����ƽ���򷵻�false�����տ����ж�ÿ���ڵ��Ƿ�ƽ�⡣

}

//������
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
	root = NULL;
}

