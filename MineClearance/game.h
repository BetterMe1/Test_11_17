#ifndef _GAME_H_
#define _GAME_H

#define EASY_COUNT 10 //�򵥼���10����

#define ROW 9 //��ʾ9��
#define COL 9 //��ʾ9��

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������
void DisplayBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void Putmine(char board[ROWS][COLS], int row, int col, int count);//����
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int count);//ɨ��

#endif

