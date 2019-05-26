#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//��ʼ������ 
//����������̺������������Ҫ�Ĳ�����һ�������Բ���ȫ����ʼ��Ϊȫ0��ȫ��*������Ҫ����һ��set�������Ρ�
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//����һ���ַ�set
{
	memset(board, set, rows*cols*sizeof(board[0][0]));
}

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)//ֻ��Ҫ��ӡ�ų˾ŵ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)//��ӡ�кź��к�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//��ӡ�ų˾ŵ�����
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//����
void SetMine(char board[ROWS][COLS], int row, int col)//��ֻ��Ҫ�����ų˾ŵĸ�����
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;//����count�����ף��ܹ�Ҫ����ʮ����
	while (count)
	{
		x = rand() % 9 + 1;//��������±�1-9
		y = rand() % 9 + 1;
		if (board[x][y] == '0')//�ж����λ����û���ף�û���׵Ļ������׵�������0��Ϊ1��ÿ���ú�һ���ף�count--�����ﲻ���ж������Ƿ�Ϸ���
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//����һ��������Χ�׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//չ��һ����Χû���׵����꣨�ݹ飩
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int ret = 0;
	ret = GetMineCount(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1>0 && y>0 && show[x - 1][y] == '*')
			OpenMine(mine, show, row, col, x - 1, y);

		if (x - 1>0 && y + 1 <= col && show[x - 1][y + 1] == '*')
			OpenMine(mine, show, row, col, x - 1, y + 1);

		if (x>0 && y + 1 <= col && show[x][y + 1] == '*')
			OpenMine(mine, show, row, col, x, y + 1);

		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '*')
			OpenMine(mine, show, row, col, x + 1, y + 1);

		if (x + 1 <= row && y>0 && show[x + 1][y] == '*')
			OpenMine(mine, show, row, col, x + 1, y);

		if (x + 1 <= row && y - 1>0 && show[x + 1][y - 1] == '*')
			OpenMine(mine, show, row, col, x + 1, y - 1);

		if (x>0 && y - 1>0 && show[x][y - 1] == '*')
			OpenMine(mine, show, row, col, x, y - 1);

		if (x - 1>0 && y - 1>0 && show[x - 1][y - 1] == '*')
			OpenMine(mine, show, row, col, x - 1, y - 1);

	}
	else
	{
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}
}

//��һ�β�ը��
void SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = 1;
	int ch = 0;
	printf("������Ҫ�Ų�����꣺>");
	scanf("%d%d", &x, &y);
	if (mine[x][y] == '1')//�����һ����������Ϊ�׽������Ϊ0������
	{
		mine[x][y] = '0';//��ȡ��Χ�׵ĸ���
		ch = GetMineCount(mine, x, y);
		show[x][y] = ch + '0';////���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCII
		while (ret)//�������пյĵط�����һ����
		{
			x = rand() % 9 + 1;//���������1-9
			y = rand() % 9 + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
			}
			ret--;
		}
	}
	OpenMine(mine, show, row, col, x, y);
	DisplayBoard(show, row, col);
}

//�ж���Ӯ 
//������жϷ��������׵ĸ�������������û�б�ը��������������ֻʣ��ʮ���׼�ʮ����*����˵��������׳ɹ���
int IsWin(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������Ҫ�Ų�����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col)//�ж��������Ч��
		{
			if (mine[x][y] == '1')//�ж��Ƿ�Ϊ�ף����������ʾ��ը������ӡ���������
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//��������ף���ȡ��Χ�׵ĸ�����չ��
			{
				int c = GetMineCount(mine, x, y);
				show[x][y] = c + '0';
				OpenMine(mine, show, row, col, x, y);
				DisplayBoard(show, row, col);
				if (IsWin(show, row, col) == EASY_COUNT)
				{
					break;
				}
			}
		}
		else//������������壬��ʾ����Ƿ�
		{
			printf("����Ƿ�\n");
		}
	}
	if (IsWin(show, row, col) == EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}