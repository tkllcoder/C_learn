#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//前序遍历 根，左子树（根，左子树，右子树），右子树（根，左子树，右子树）
//递归调用，分治算法  结束条件 注意递归调用的入口和返回及结束的出口
void PrevOrder(BTNode* root)
{
	//结束条件
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);//根
	PrevOrder(root->left);//左子树递归
	PrevOrder(root->right);//右子树递归
}

//中序遍历
void InOrder(BTNode* root)
{
	//结束条件
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);//左子树递归
	printf("%c ", root->data);//根
	InOrder(root->right);//右子树递归
}

//后序遍历
void PostOrder(BTNode* root)
{
	//结束条件
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);//左子树递归
	PostOrder(root->right);//右子树递归
	printf("%c ", root->data);//根
}

//节点个数 同样是递归调用
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

//叶子节点个数
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

//层序遍历 思想用队列来实现
void LevelOrder(BTNode* root)
{
	//定义队列并初始化
	Queue q;
	QueueInit(&q);

	//1.将根节点入队
	QueuePush(&q, root);
	//循环:队列不为空 2.一个节点出队 3.再将出队节点的左右孩子入队，为空则不入。
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

//前序遍历并返回数组及数组大小
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
	//节点个数 并开辟空间返回
	int size = TreeSize(root);
	char* a = (char*)malloc(sizeof(char) * size);
	*returnSize = size;

	int i = 0;
	//传入根节点和初始下标，进行前序遍历获取数组元素
	PrevOrder10(root, a, &i);
	return a;
}

//树的深度  依然分治思想递归 返回左子树的深度与右子树深度的最大值并加1
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

//判断一棵二叉树是否为高度平衡的二叉树  每个节点的子树高度差的绝对值不超过1
bool IsBalanced(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int deepL = TreeDeep(root->left);
	int deepR = TreeDeep(root->right);
	
	return abs(deepL - deepR) < 2 && IsBalanced(root->left) && IsBalanced(root->right);
	//判断自己节点，和子树是否平衡，若不平衡则返回false，最终可以判断每个节点是否平衡。

}

//树销毁
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

