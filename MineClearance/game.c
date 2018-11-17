#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
	memset(board, set, rows*cols*sizeof(board[0][0]));
}
void DisplayBoard(char board[ROWS][COLS], int row, int col){
	int i, j = 0;
	printf("------------------------\n");
	for (i = 0; i <= row; i++){
		for (j = 0; j <= col; j++){
			if (i == 0||j==0){
				if (i == 0){
					printf("%d ", j);
				}
				else{
					printf("%d ", i);
				}
			}
			else{
				printf("%c ", board[i][j]);
			}
		}
		printf("\n");
	}
	printf("------------------------\n");
}
void Putmine(char board[ROWS][COLS], int row, int col, int count){
	int c = 0;//埋好的雷的个数
	int i = 0;
	int j = 0;
	do{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] =='0'){//保证雷的个数为 count个
			board[i][j] = '1';
			c++;
		}	
	} while (count-c);
}
/*统计雷的个数*/
int MineCount(char mine[ROWS][COLS], int i, int j){
	return (mine[i - 1][j] +
		mine[i - 1][j + 1] +
		mine[i][j + 1] +
		mine[i + 1][j + 1] +
		mine[i + 1][j] +
		mine[i + 1][j - 1] +
		mine[i][j - 1] +
		mine[i - 1][j - 1]) - 8 * '0';
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int count){
	int i, j;//行列坐标
	int remine = ROW*COL - EASY_COUNT;//剩余的不是雷的坐标；
	int playcount = 0;//玩家排雷的次数
	do{
		printf("请输入要排查的坐标（如：a,b）:>");
		scanf("%d,%d", &i, &j);
		//printf("%c\n", mine[i][j]);
		if (i >= 1 && i <= 9 && j >= 1 && j <= 9){
			if (show[i][j] == '*'){
				if (mine[i][j] == '1'){
					if (playcount == 0){//此时说明玩家首次排雷且踩到雷了
						mine[i][j] = '0';
						Putmine(mine, ROW, COL, 1);//重新放雷，保证玩家在第一把不踩雷
						playcount = 1;
						show[i][j] = '0';
					//	DisplayBoard(mine, ROW, COL);
						DisplayBoard(show, ROW, COL);
					}
					else{
						printf("很遗憾，你被炸死了！\n");
						printf("雷阵布局如下：\n");
						DisplayBoard(mine, ROW, COL);
					}
				}
				else{
					if (MineCount(mine, i, j) == 0){
						show[i][j] = '0';
						DisplayBoard(show, ROW, COL);
					}
					else{
						show[i][j] = MineCount(mine, i, j) + '0';
						DisplayBoard(show, ROW, COL);
					}
					remine--;
					playcount = 1;
				}
			}
			else{
				printf("此坐标已被排查过，请重新输入！\n");
			}
		}
		else{
			printf("坐标输入有误，请重新输入！\n");
		}
	} while (remine);
	printf("恭喜您,排雷成功！\n");
	printf("雷阵布局如下：\n");
	DisplayBoard(mine, ROW, COL);
}
