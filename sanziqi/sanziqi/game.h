#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���峣��  ������������
#define ROW 3
#define COL 3

//��������
void menu();//��Ϸ���˵�����
void game();//��������Ϸ�����������ܶ���ģ��

//��ģ��
void Initboard(char board[ROW][COL], int row, int col);//��ֳ�ʼ��������ά�ַ��ͺ����洢���ӱ���
void displayboard(char board[ROW][COL], int row, int col);//���̴�ӡ�������������̿�ܲ���ʾ���״̬
void playermove(char board[ROW][COL], int row, int col);//������庯��
void computermove(char board[ROW][COL], int row, int col);//�������庯��
char IsWin(char board[ROW][COL], int row, int col);//�ж��Ƿ����Ӯ��
int IsFull(char board[ROW][COL], int row, int col);//�ж�����Ƿ�����