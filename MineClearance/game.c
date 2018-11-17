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
	int c = 0;//��õ��׵ĸ���
	int i = 0;
	int j = 0;
	do{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] =='0'){//��֤�׵ĸ���Ϊ count��
			board[i][j] = '1';
			c++;
		}	
	} while (count-c);
}
/*ͳ���׵ĸ���*/
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
	int i, j;//��������
	int remine = ROW*COL - EASY_COUNT;//ʣ��Ĳ����׵����ꣻ
	int playcount = 0;//������׵Ĵ���
	do{
		printf("������Ҫ�Ų�����꣨�磺a,b��:>");
		scanf("%d,%d", &i, &j);
		//printf("%c\n", mine[i][j]);
		if (i >= 1 && i <= 9 && j >= 1 && j <= 9){
			if (show[i][j] == '*'){
				if (mine[i][j] == '1'){
					if (playcount == 0){//��ʱ˵������״������Ҳȵ�����
						mine[i][j] = '0';
						Putmine(mine, ROW, COL, 1);//���·��ף���֤����ڵ�һ�Ѳ�����
						playcount = 1;
						show[i][j] = '0';
					//	DisplayBoard(mine, ROW, COL);
						DisplayBoard(show, ROW, COL);
					}
					else{
						printf("���ź����㱻ը���ˣ�\n");
						printf("���󲼾����£�\n");
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
				printf("�������ѱ��Ų�������������룡\n");
			}
		}
		else{
			printf("���������������������룡\n");
		}
	} while (remine);
	printf("��ϲ��,���׳ɹ���\n");
	printf("���󲼾����£�\n");
	DisplayBoard(mine, ROW, COL);
}
