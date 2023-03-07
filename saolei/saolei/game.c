#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//主菜单函数
void menu()
{
	printf("***************************************\n");
	printf("********       扫雷游戏         *******\n");
	printf("********    1.play   0.exit     *******\n");
	printf("***************************************\n");

}

//玩游戏函数
//扫雷游戏规则  1.非零数字表示数字周围的8个位置中有几个雷
//2.数字0则打开周围不是雷的格子 此处不写
//3.有雷点到则失败
void game()
{
	char mine[ROWS][COLS] = { 0 };//雷的放置数组
	char show[ROWS][COLS] = { 0 };//周围雷的遍历
	//初始化棋盘
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');

	//打印棋盘
	//Display_board(mine, ROW, COL);
	Display_board(show, ROW, COL);

	//布置雷到mine数组中
	Set_mine(mine, ROW, COL, count);
	Display_board(mine, ROW, COL);

	//扫雷
	//输入坐标，
	//1. 是雷，则打印很遗憾你被炸死了。
	//2. 不是雷，然后遍历mine中的坐标的周围雷的数量，返回并保存到show数组中
	int i = 0;
	printf("初级扫雷，总格数81个，雷10个\n");
	printf("-------------------------------\n");
	while (i < mine_count)
	{
		int p = 0;
		int q = 0;
		int ret = 0;
		printf("请输入坐标:");
		scanf("%d %d", &p, &q);
		if (p >= 1 && p <= ROW && q >= 1 && q <= COL)//坐标是否有效
		{
			if (mine[p][q] == '1')
			{
				printf("很遗憾，你被炸死了，游戏结束\n");
				break;
			}
			else
			{
				//遍历坐标周围雷的数量
				ret = Find_mine(mine, p, q);
				show[p][q] = ret + '0';//整型转换为字符型，加一个字符0的ASCII值
				//打印show数组
				Display_board(show, ROW, COL);
				i++;

			}
		}
		else
			printf("坐标输入无效，请重新输入\n");
	}
	//3. 当非雷被排完之后，则打印恭喜你通关成功
	if (i == mine_count)
	{
		printf("恭喜了，通关成功！！\n");
		Display_board(show, ROW, COL);
	}

}

//初始化棋盘
void Init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("*******   扫雷游戏    ********\n");

	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}

}

//布置雷
void Set_mine(char mine[ROWS][COLS], int row, int col, int n) 
{
	int i = 0;
	int x = 0;
	int y = 0;
	while (i < n)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] == '0')//查看是否布置了
		{
			mine[x][y] = '1';//布置为雷
			i++;
		}
	}
	
}

//遍历坐标周围雷的数量
int Find_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';//字符转换为整型-'0'

}