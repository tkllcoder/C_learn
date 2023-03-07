#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//��������
void menu()//���˵�����
{
	printf("*******************************\n");
	printf("********    1.play     ********\n");
	printf("********    0.exit     ********\n");
	printf("*******************************\n");
}

//������Ϸ����
void game()
{
	char ret = 0;
	//��ʼ�����̵�ֵ
	char board[ROW][COL];
	Initboard(board, ROW, COL);
	//��ӡ����
	displayboard(board, ROW, COL);
	//ѭ������
	while (1)
	{
		//������壨���룩
		printf("������壺\n");
		playermove(board, ROW, COL);
		//��ӡ����
		displayboard(board, ROW, COL);
		//�ж���Ӯ ���ر�־1.'*'���Ӯ2.'#'����Ӯ3.'Q'ƽ��4.'C'��δ����������
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//��Ϸ����
			break;
		//�������壨����ո�
		printf("�������壺\n");
		computermove(board, ROW, COL);
		//��ӡ����
		displayboard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
		printf("\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
		printf("\n");
	}
	else
	{
		printf("ƽ��\n");
		printf("\n");
	}
	
}

//�������ݳ�ʼ������
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

//���̴�ӡ���� �����д�ӡ
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)//����������
	{
		//��ӡ����
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)//���һ��û�зָ���
				printf("|");
		}
		printf("\n");
		//�����ָ�
		if (i < ROW - 1)//���һ��û�зָ���
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)//���һ��û�зָ�
					printf("|");
			}
		}
		printf("\n");
	}
}

//������庯��
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���������꣺");
	while (1)
	{
		scanf("%d %d", &x, &y);
		//�ж��������Ч��
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����ѱ�ռ�ã�����������:\n");
		}
		else
			printf("������Ч������������:\n");
	}
	
}

//�������庯��
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//�ж������Ƿ�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж���Ӯ����̺���
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int flag = 0;
	//��һ���Ƿ�������ͬ
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];//������Ӧ�ķ���
		}
	}

	//��һ���Ƿ�������ͬ
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];//������Ӧ�ķ���
		}
	}
	
	//���Խ����Ƿ�������ͬ
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[1][1];
	//������������� �ж��Ƿ�ƽ�֣����ж������Ƿ�����
	flag = IsFull(board, row, col);
	if (flag == 1)
		return 'Q';
	//������������������
	return 'C';
}

//�ж������Ƿ�����
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
				return 0;//����û��
			}
		}
	}
	return 1;//��������

}