/**
 * @file print.c
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 输出模块方法实现
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "print.h"

void PrintEdge(int i, int j)
{
	if (i == 1 && j == 1)
	{
		printf("┏");
	}
	else if (i == 1 && j == GRID_NUM - 1)
	{
		printf("━┓");
	}
	else if (i == GRID_NUM - 1 && j == 1)
	{
		printf("┗");
	}
	else if (i == GRID_NUM - 1 && j == GRID_NUM - 1)
	{
		printf("━┛");
	}
	else if (i == 1 && j != GRID_NUM - 1 && j != 1)
	{
		printf("━┯");
	}
	else if (i == GRID_NUM - 1 && j != GRID_NUM - 1 && j != 1)
	{
		printf("━┷");
	}
	else if (j == 1 && i != GRID_NUM - 1 && i != 1)
	{
		printf("┠");
	}
	else if (j == GRID_NUM - 1 && i != GRID_NUM - 1 && i != 1)
	{
		printf("─┨");
	}
	else
	{
		printf("─┼");
	}
}

void PrintChessBoard()
{
	for (int i = 0; i < GRID_NUM; i++)
	{
		if (i == 0)
		{
			printf("  ");
			/* 打印列坐标. */
			for (int j = 1; j < GRID_NUM; j++)
			{
				printf("%-2d", j);
			}

			printf("\n");

			continue;
		}
		for (int j = 0; j < GRID_NUM; j++)
		{
			/* 打印行坐标. */
			if (j == 0)
			{
				printf("%2d", i);
				continue;
			}

			/* 如果 (i, j) 处有棋子. */
			if (chessBoard[i][j] != BLANK)
			{
				/* 如果是打印时宽度为 1 的边界. */
				if ((i == 1 && j == 1) || (i == GRID_NUM - 1 && j == 1) || (j == 1 && i != GRID_NUM - 1 && i != 1))
				{
					/* 如果是黑子. */
					if (chessBoard[i][j] == BLACK)
					{
						printf("●");
					}
					/* 如果是白子. */
					else if (chessBoard[i][j] == WHITE)
					{
						printf("○");
					}
				}
				else
				{
					if (chessBoard[i][j] == BLACK)
					{
						printf("─●");
					}
					else if (chessBoard[i][j] == WHITE)
					{
						printf("─○");
					}
				}
			}
			/* 如果没有棋子, 则根据坐标判断应该绘制什么. */
			else
			{
				PrintEdge(i, j);
			}
		}

		printf("\n");
	}

	return;
}
