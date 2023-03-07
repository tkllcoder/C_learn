#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("玩游戏\n");
			game();
		}
		else if (input == 0)
		{
			printf("退出游戏\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入：");
		}
	}
	return 0;
}