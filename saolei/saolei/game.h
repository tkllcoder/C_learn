#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//存放雷的信息+2，相当于9*9的扫雷区
#define COL 9

#define ROWS ROW + 2//存放雷的信息+2，相当于9*9的扫雷区
#define COLS COL + 2

#define count 10
#define mine_count ROW*COL - count//非雷的数量

void menu();//主菜单
void game();//玩游戏
void Init_board(char board[ROWS][COLS], int rows, int cols, char set);//初始化棋盘
void Display_board(char board[ROWS][COLS], int row, int col);//打印棋盘
void Set_mine(char mine[ROWS][COLS], int row, int col, int n);//布置雷
int Find_mine(char mine[ROWS][COLS], int x, int y);//遍历坐标周围雷的数量