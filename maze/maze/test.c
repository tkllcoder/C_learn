#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include"stack.h"

/////////迷宫之最短路径+体力值
//打印迷宫
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

//定义栈
ST path;
ST minpath;//定义一个最短路径的栈
//打印路径
void PrintPath(ST* ps)
{
	ST rPath;//重新定义一个栈将获得的栈倒置输出
	StackInit(&rPath);
	while (!StackEmpty(ps))
	{
		//path栈顶的数据传给rPath入栈，path出栈
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

//判断是否可走
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

//栈的深层拷贝
void StackCopy(ST* ppath, ST* minppath)
{
	minppath->a = (STDataType*)malloc(sizeof(STDataType) * ppath->capacity);//重新创建一块相同的空间
	for (int i = 0; i < ppath->top; i++)
	{
		minppath->a[i] = ppath->a[i];
	}
	minppath->capacity = ppath->capacity;
	minppath->top = ppath->top;
}

//寻找通路，深度优先遍历。看它的上下左右是否为通路，递归回溯算法。
void GetPass(int** maze, int n, int m, PT cur, int p)
{
	StackPush(&path, cur);//入栈
	if (cur.row == 0 && cur.col == m - 1)//出口在右上角 多次找到出口 判断最短路径
	{
		//判断最短路径
		if (p >= 0 && (StackEmpty(&minpath) || StackSize(&path) < StackSize(&minpath)))
		{
			StackDestroy(&minpath);
			StackCopy(&path, &minpath);//栈的深层拷贝
		}
	}
	//设当前的坐标的值为2
	maze[cur.row][cur.col] = 2;
	PT next;
	
	//判断上方
	next.row = cur.row - 1;
	next.col = cur.col;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p - 3);
	}

	//判断下方
	next.row = cur.row + 1;
	next.col = cur.col;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p);
	}

	//判断左方
	next.row = cur.row;
	next.col = cur.col - 1;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p - 1);
	}

	//判断右方
	next.row = cur.row;
	next.col = cur.col + 1;
	if (IsPass(maze, next.row, next.col, n, m))
	{
		GetPass(maze, n, m, next, p - 1);
	}
	//上下左右都没路，则返回false
	StackPop(&path);//出栈
	maze[cur.row][cur.col] = 0;//恢复成通路
}

int main()
{
	//以二维数组模拟迷宫，1为墙，0为通路，2为走过的路
	int N = 0;
	int M = 0;
	int P = 0;//体力值
	scanf("%d %d %d", &N, &M, &P);

	//动态创建二维数组(大小不固定)  二级指针代表一个指针数组的首地址
	//每个指针指向一个M个元素的数组
	int** maze = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		maze[i] = (int*)malloc(sizeof(int) * M);
	}

	//输入数组形式
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &maze[i][j]);  
		}
	}

	//PrintMaze(maze, N, M);//判断输入的
	/*5 5  唯一路径
	0 1 1 0 0
	0 0 1 1 0
	1 0 1 1 1
	0 0 0 1 0
	1 1 0 0 0*/

	//青蛙逃迷宫，最短路径和体力值 向上体力值-3，向左向右-1，向下不消耗体力。
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
	//内存释放
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