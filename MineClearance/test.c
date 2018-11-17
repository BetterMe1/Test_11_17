/*
date：2018/11/17
author:BetterMe1
program:Mine Clearance
compiler:Visual Studio 2013
注：只实现基础功能和第一次不踩雷的拓展功能
*/

/*测试部分*/
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void menu(){
	printf("************  扫雷小游戏  ************\n");
	printf("******  1.进入游戏  2.退出游戏  ******\n");
	printf("**************************************\n");
}
void game(){
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };//显示雷,给玩家看
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//初始化棋盘
	Putmine(mine, ROW, COL,EASY_COUNT);//埋雷
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);//打印棋盘
	Findmine(mine,show, ROW, COL, EASY_COUNT);//扫雷
}
void test(){
	int input = 0;
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入有误，请重新选择！\n");
			break;
		}
	} while ((input - 2));
}
void main(){
	test();
	system("pause");
}