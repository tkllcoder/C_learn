#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//����׵���Ϣ+2���൱��9*9��ɨ����
#define COL 9

#define ROWS ROW + 2//����׵���Ϣ+2���൱��9*9��ɨ����
#define COLS COL + 2

#define count 10
#define mine_count ROW*COL - count//���׵�����

void menu();//���˵�
void game();//����Ϸ
void Init_board(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������
void Display_board(char board[ROWS][COLS], int row, int col);//��ӡ����
void Set_mine(char mine[ROWS][COLS], int row, int col, int n);//������
int Find_mine(char mine[ROWS][COLS], int x, int y);//����������Χ�׵�����