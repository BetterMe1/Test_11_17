/*
date��2018/11/17
author:BetterMe1
program:Mine Clearance
compiler:Visual Studio 2013
ע��ֻʵ�ֻ������ܺ͵�һ�β����׵���չ����
*/

/*���Բ���*/
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void menu(){
	printf("************  ɨ��С��Ϸ  ************\n");
	printf("******  1.������Ϸ  2.�˳���Ϸ  ******\n");
	printf("**************************************\n");
}
void game(){
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };//��ʾ��,����ҿ�
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//��ʼ������
	Putmine(mine, ROW, COL,EASY_COUNT);//����
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);//��ӡ����
	Findmine(mine,show, ROW, COL, EASY_COUNT);//ɨ��
}
void test(){
	int input = 0;
	do{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("��������������ѡ��\n");
			break;
		}
	} while ((input - 2));
}
void main(){
	test();
	system("pause");
}