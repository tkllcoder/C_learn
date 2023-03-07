#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

//主函数
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	//游戏进入界面，可以一直玩游戏do...while()
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
			
	} while (input);
	return 0;
}