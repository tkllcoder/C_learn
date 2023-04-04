#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include"stack.h"

/////////�Թ�֮���·��+����ֵ
//��ӡ�Թ�
void PrintMaze(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//����ջ
ST path;
ST minpath;//����һ�����·����ջ
//��ӡ·��
void PrintPath(ST* ps)
{
	ST rPath;//���¶���һ��ջ����õ�ջ�������
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		//pathջ�������ݴ���rPath��ջ��path��ջ
		StackPush(&rPath, StackTop(ps));
		StackPop(ps);
	}
	while (!StackEmpty(&rPath))
	{
		PT pt = StackTop(&rPath);
		printf("(%d,%d)\n", pt.row, pt.col);
		StackPop(&rPath);
	}
	StackDestroy(&rPath);
}

//�ж��Ƿ����
bool IsPass(int** maze, int row, int col, int n, int m)
{
	if (row >= 0 && row < n
		&& col >= 0 && col < m
		&& maze[row][col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//ջ����㿽��
void StackCopy(ST* ppath, ST* minppath)
{
	minppath->a = (STDataType*)malloc(sizeof(STDataType) * ppath->capacity);//���´���һ����ͬ�Ŀռ�
	for (int i = 0; i < ppath->top; i++)
	{
		minppath->a[i] = ppath->a[i];
	}
	minppath->capacity = ppath->capacity;
	minppath->top = ppath->top;
}

//Ѱ��ͨ·��������ȱ��������������������Ƿ�Ϊͨ·���ݹ�����㷨��
void GetPass(int** maze, int n, int m, PT cur, int p)
{
	StackPush(&path, cur);//��ջ
	if (cur.row == 0 && cur.col == m - 1)//���������Ͻ� ����ҵ����� �ж����·��
	{
		//�ж����·��
		if (p >= 0 && (StackEmpty(&minpath) || StackSize(&path) < StackSize(&minpath)))
		{
			StackDestroy(&minpath);
			StackCopy(&path, &minpath);//ջ����㿽��
		}
	}
	//�赱ǰ�������ֵΪ2
	maze[cur.row][cur.col] = 2;
	PT next;
	
	//�ж��Ϸ�
	next.row = cur.row - 1;
	next.col = cur.col;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p - 3);
	}

	//�ж��·�
	next.row = cur.row + 1;
	next.col = cur.col;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p);
	}

	//�ж���
	next.row = cur.row;
	next.col = cur.col - 1;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p - 1);
	}

	//�ж��ҷ�
	next.row = cur.row;
	next.col = cur.col + 1;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p - 1);
	}
	//�������Ҷ�û·���򷵻�false
	StackPop(&path);//��ջ
	maze[cur.row][cur.col] = 0;//�ָ���ͨ·
}

int main()
{
	//�Զ�ά����ģ���Թ���1Ϊǽ��0Ϊͨ·��2Ϊ�߹���·
	int N = 0;
	int M = 0;
	int P = 0;//����ֵ
	scanf("%d %d %d", &N, &M, &P);

	//��̬������ά����(��С���̶�)  ����ָ�����һ��ָ��������׵�ַ
	//ÿ��ָ��ָ��һ��M��Ԫ�ص�����
	int** maze = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		maze[i] = (int*)malloc(sizeof(int) * M);
	}

	//����������ʽ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &maze[i][j]);  
		}
	}

	//PrintMaze(maze, N, M);//�ж������
	/*5 5  Ψһ·��
	0 1 1 0 0
	0 0 1 1 0
	1 0 1 1 1
	0 0 0 1 0
	1 1 0 0 0*/

	//�������Թ������·��������ֵ ��������ֵ-3����������-1�����²�����������
	/*4 4 10
	0 1 1 0
	0 0 1 0
	1 0 0 0
	1 1 0 0*/

	StackInit(&path);
	StackInit(&minpath);

	PT entry = { 0,0 };
	GetPass(maze, N, M, entry, P);

	if (!StackEmpty(&minpath))
	{
		PrintPath(&minpath);
	}
	else
	{
		printf("It can't escape\n");
	}
	//�ڴ��ͷ�
	for (int i = 0; i < N; i++)
	{
		free(maze[i]);
	}
	free(maze);
	maze = NULL;
	StackDestroy(&path);
	StackDestroy(&minpath);

	return 0;
}