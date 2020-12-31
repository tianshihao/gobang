/**
 * @file define.c
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 宏定义与外部变量定义
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "define.h"

/* 定义外部变量. */
int chessBoard[GRID_NUM][GRID_NUM];       /// 棋盘.
int piece;                                /// 玩家.
point feasibleMoves[MAX_DEPTH + 1][1000]; /// 可行招法
point currentMove[MAX_DEPTH + 1];         /// 当前招法.
point bestMove;                           /// 最好招法.
