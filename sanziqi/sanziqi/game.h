#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义常量  三子棋或多子棋
#define ROW 3
#define COL 3

//函数声明
void menu();//游戏主菜单函数
void game();//三子棋游戏函数，包含很多子模块

//子模块
void Initboard(char board[ROW][COL], int row, int col);//棋局初始化，将二维字符型函数存储棋子变量
void displayboard(char board[ROW][COL], int row, int col);//棋盘打印函数，构建棋盘框架并显示棋局状态
void playermove(char board[ROW][COL], int row, int col);//玩家下棋函数
void computermove(char board[ROW][COL], int row, int col);//电脑下棋函数
char IsWin(char board[ROW][COL], int row, int col);//判断是否产生赢家
int IsFull(char board[ROW][COL], int row, int col);//判断棋局是否下满