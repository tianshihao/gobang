/**
 * @file evaluate.c
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 估值模块方法实现
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "evaluate.h"

static int valueMap[GRID_NUM][GRID_NUM] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 6, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 6, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Evaluate(point pos, int piece)
{
    return -evaluate(pos, piece, 1) - evaluate(pos, piece, 2);
}

int evaluate(point pos, int player1, int player2)
{
    int val = valueMap[pos.x][pos.y];
    int numoftwo = 0;

    for (int i = 1; i <= 8; i++)
    {
        /* 活四. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, -3) == player2 && GetLine(pos, i, -4) == player2 && GetLine(pos, i, -5) == 0)
        {
            val += 300000;
            if (player1 != player2)
            {
                val -= 500;
            }
            continue;
        }

        /* 死四A 21111*. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, -3) == player2 && GetLine(pos, i, -4) == player2 && (GetLine(pos, i, -5) == 3 - player2 || GetLine(pos, i, -5) == -1))
        {
            val += 250000;
            if (player1 != player2)
            {
                val -= 500;
            }
            continue;
        }

        /* 死四B 111*1. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, -3) == player2 && GetLine(pos, i, 1) == player2)
        {
            val += 240000;
            if (player1 != player2)
            {
                val -= 500;
            }
            continue;
        }

        /* 死四C 11*11. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, 1) == player2 && GetLine(pos, i, 2) == player2)
        {
            val += 230000;
            if (player1 != player2)
            {
                val -= 500;
            }
            continue;
        }

        /* 活三 近3位置 111*0. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, -3) == player2)
        {
            if (GetLine(pos, i, 1) == 0)
            {
                val += 750;
                if (GetLine(pos, i, -4) == 0)
                {
                    val += 3150;
                    if (player1 != player2)
                    {
                        val -= 300;
                    }
                }
            }
            if ((GetLine(pos, i, 1) == 3 - player2 || GetLine(pos, i, 1) == -1) && GetLine(pos, i, -4) == 0)
            {
                val += 500;
            }
            continue;
        }

        /* 活三 远3位置 1110*. */
        if (GetLine(pos, i, -1) == 0 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, -3) == player2 && GetLine(pos, i, -4) == player2)
        {
            val += 350;
            continue;
        }

        /* 死三 11*1. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, 1) == player2)
        {
            val += 600;
            if (GetLine(pos, i, -3) == 0 && GetLine(pos, i, 2) == 0)
            {
                val += 3150;
                continue;
            }
            if ((GetLine(pos, i, -3) == 3 - player2 || GetLine(pos, i, -3) == -1) && (GetLine(pos, i, 2) == 3 - player2 || GetLine(pos, i, 2) == -1))
            {
                continue;
            }
            else
            {
                val += 700;
                continue;
            }
        }

        /* 活二的个数. */
        if (GetLine(pos, i, -1) == player2 && GetLine(pos, i, -2) == player2 && GetLine(pos, i, -3) != 3 - player2 && GetLine(pos, i, 1) != 3 - player2)
        {
            numoftwo++;
        }

        /* 其余散棋. */
        int numOfplyer = 0;           /* 因为方向会算两次？ */
        for (int k = -4; k <= 0; k++) /* ++++* +++*+ ++*++ +*+++ *++++ */
        {
            int temp = 0;
            for (int l = 0; l <= 4; l++)
            {
                if (GetLine(pos, i, k + l) == player2)
                {
                    temp++;
                }
                else if (GetLine(pos, i, k + l) == 3 - player2 || GetLine(pos, i, k + l) == -1)
                {
                    temp = 0;
                    break;
                }
            }
            numOfplyer += temp;
        }
        val += numOfplyer * 15;
        if (numOfplyer != 0)
        {
        }
    }

    if (numoftwo >= 2)
    {
        val += 3000;
        if (player1 != player2)
        {
            val -= 100;
        }
    }
    return val;
}

int GetLine(point pos, int i, int j)
{
    int x = pos.x, y = pos.y;
    switch (i)
    {
    case 1:
        x = x + j;
        break;
    case 2:
        x = x + j;
        y = y + j;
        break;
    case 3:
        y = y + j;
        break;
    case 4:
        x = x - j;
        y = y + j;
        break;
    case 5:
        x = x - j;
        break;
    case 6:
        x = x - j;
        y = y - j;
        break;
    case 7:
        y = y - j;
        break;
    case 8:
        x = x + j;
        y = y - j;
    }

    if (x < 1 || y < 1 || x > 15 || y > 15) // 越界处理
    {
        return -1;
    }

    return chessBoard[x][y];
}
