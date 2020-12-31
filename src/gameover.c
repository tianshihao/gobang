#include "gameover.h"

STATUS Gameover(point pos, int piece)
{

    int count = 0, winflag = 0; /* 初始化; */

    /****************************垂直方向判断****************************/

    /* 向上读取 5 个点; */
    for (int i = pos.x, j = pos.y; i >= 1 && count++ <= 5; i--)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break;
    }
    count = 0;

    /* 向下读取 5 个点; */
    for (int i = pos.x + 1, j = pos.y; i <= 15 && count++ <= 5; i++)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break;
    }
    count = 0;

    if (winflag >= 5)
        return TRUE;
    else
        winflag = 1;

    /****************************水平方向判断****************************/

    /* 向右读取 5 个点; */
    for (int i = pos.x, j = pos.y + 1; j <= 15 && count++ <= 5; j++)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break; /* 如果不是,就不是连续相同的棋子 */
    }
    count = 0;

    /* 往向左读取 5 个点; */
    for (int i = pos.x, j = pos.y - 1; j >= 1 && count++ <= 5; j--)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break; /* 如果不是,就不是连续相同的棋子 */
    }
    count = 0;

    if (winflag >= 5)
        return TRUE;
    else
        winflag = 1;

    /*************************主对角线方向的判断*************************/

    /* 读取右下方; */
    for (int i = pos.x + 1, j = pos.y + 1; i <= 15 && j <= 15 && count++ < 5; i++, j++)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break;
    }
    count = 0;

    /* 读取左上方; */
    for (int i = pos.x - 1, j = pos.y - 1; i >= 1 && j >= 1 && count++ < 5; i--, j--)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break; /* 如果不是,就不是连续相同的棋子 */
    }
    count = 0;

    if (winflag >= 5)
        return TRUE;
    else
        winflag = 1;

    /*************************斜对角线方向的判断*************************/

    /* 读取右上方; */
    for (int i = pos.x - 1, j = pos.y + 1; i >= 1 && j <= 15 && count++ < 5; i--, j++)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break; /* 如果不是,就不是连续相同的棋子 */
    }
    count = 0;

    /* 读取左下方; */
    for (int i = pos.x + 1, j = pos.y - 1; i <= 15 && j >= 1 && count++ < 5; i++, j--)
    {
        if (chessBoard[i][j] == piece)
            winflag++;
        else
            break; /* 如果不是,就不是连续相同的棋子 */
    }
    count = 0;

    if (winflag >= 5)
    {
        return TRUE;
    }
    else
    {
        winflag = 1;
    }

    return FALSE;
}
