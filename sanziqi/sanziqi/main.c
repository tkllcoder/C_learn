#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

//������
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	//��Ϸ������棬����һֱ����Ϸdo...while()
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�����������������\n");
				break;
		}
			
	} while (input);
	return 0;
}