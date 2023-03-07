#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//���˵�����
void menu()
{
	printf("***************************************\n");
	printf("********       ɨ����Ϸ         *******\n");
	printf("********    1.play   0.exit     *******\n");
	printf("***************************************\n");

}

//����Ϸ����
//ɨ����Ϸ����  1.�������ֱ�ʾ������Χ��8��λ�����м�����
//2.����0�����Χ�����׵ĸ��� �˴���д
//3.���׵㵽��ʧ��
void game()
{
	char mine[ROWS][COLS] = { 0 };//�׵ķ�������
	char show[ROWS][COLS] = { 0 };//��Χ�׵ı���
	//��ʼ������
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');

	//��ӡ����
	//Display_board(mine, ROW, COL);
	Display_board(show, ROW, COL);

	//�����׵�mine������
	Set_mine(mine, ROW, COL, count);
	Display_board(mine, ROW, COL);

	//ɨ��
	//�������꣬
	//1. ���ף����ӡ���ź��㱻ը���ˡ�
	//2. �����ף�Ȼ�����mine�е��������Χ�׵����������ز����浽show������
	int i = 0;
	printf("����ɨ�ף��ܸ���81������10��\n");
	printf("-------------------------------\n");
	while (i < mine_count)
	{
		int p = 0;
		int q = 0;
		int ret = 0;
		printf("����������:");
		scanf("%d %d", &p, &q);
		if (p >= 1 && p <= ROW && q >= 1 && q <= COL)//�����Ƿ���Ч
		{
			if (mine[p][q] == '1')
			{
				printf("���ź����㱻ը���ˣ���Ϸ����\n");
				break;
			}
			else
			{
				//����������Χ�׵�����
				ret = Find_mine(mine, p, q);
				show[p][q] = ret + '0';//����ת��Ϊ�ַ��ͣ���һ���ַ�0��ASCIIֵ
				//��ӡshow����
				Display_board(show, ROW, COL);
				i++;

			}
		}
		else
			printf("����������Ч������������\n");
	}
	//3. �����ױ�����֮�����ӡ��ϲ��ͨ�سɹ�
	if (i == mine_count)
	{
		printf("��ϲ�ˣ�ͨ�سɹ�����\n");
		Display_board(show, ROW, COL);
	}

}

//��ʼ������
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

//��ӡ����
void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("*******   ɨ����Ϸ    ********\n");

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

//������
void Set_mine(char mine[ROWS][COLS], int row, int col, int n) 
{
	int i = 0;
	int x = 0;
	int y = 0;
	while (i < n)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] == '0')//�鿴�Ƿ�����
		{
			mine[x][y] = '1';//����Ϊ��
			i++;
		}
	}
	
}

//����������Χ�׵�����
int Find_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';//�ַ�ת��Ϊ����-'0'

}