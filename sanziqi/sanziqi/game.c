#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//函数定义
void menu()//主菜单函数
{
	printf("*******************************\n");
	printf("********    1.play     ********\n");
	printf("********    0.exit     ********\n");
	printf("*******************************\n");
}

//整个游戏函数
void game()
{
	char ret = 0;
	//初始化棋盘的值
	char board[ROW][COL];
	Initboard(board, ROW, COL);
	//打印棋盘
	displayboard(board, ROW, COL);
	//循环下棋
	while (1)
	{
		//玩家下棋（输入）
		printf("玩家下棋：\n");
		playermove(board, ROW, COL);
		//打印棋盘
		displayboard(board, ROW, COL);
		//判断输赢 返回标志1.'*'玩家赢2.'#'电脑赢3.'Q'平局4.'C'还未结束，继续
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//游戏结束
			break;
		//电脑下棋（随机空格）
		printf("电脑下棋：\n");
		computermove(board, ROW, COL);
		//打印棋盘
		displayboard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
		printf("\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
		printf("\n");
	}
	else
	{
		printf("平局\n");
		printf("\n");
	}
	
}

//棋盘内容初始化函数
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
		
}

//棋盘打印函数 分行列打印
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)//控制内容行
	{
		//打印内容
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)//最后一列没有分隔符
				printf("|");
		}
		printf("\n");
		//制作分隔
		if (i < ROW - 1)//最后一行没有分隔符
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)//最后一列没有分隔
					printf("|");
			}
		}
		printf("\n");
	}
}

//玩家下棋函数
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入坐标：");
	while (1)
	{
		scanf("%d %d", &x, &y);
		//判断坐标的有效性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被占有
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标已被占用，请重新输入:\n");
		}
		else
			printf("坐标无效，请重新输入:\n");
	}
	
}

//电脑下棋函数
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//判断坐标是否被占有
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断输赢或过程函数
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int flag = 0;
	//看一行是否三个相同
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];//返回相应的符号
		}
	}

	//看一列是否三个相同
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];//返回相应的符号
		}
	}
	
	//看对角线是否三个相同
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[1][1];
	//三种情况均不是 判断是否平局，即判断棋盘是否满了
	flag = IsFull(board, row, col);
	if (flag == 1)
		return 'Q';
	//以上情况都不是则继续
	return 'C';
}

//判断棋盘是否下满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了

}