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
		printf("��ѡ��");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("����Ϸ\n");
			game();
		}
		else if (input == 0)
		{
			printf("�˳���Ϸ\n");
			break;
		}
		else
		{
			printf("����������������룺");
		}
	}
	return 0;
}