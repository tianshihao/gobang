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

#ifndef DEFINE_H_
#define DEFINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum PIECE
{
	BLANK, /* 空点. */
	BLACK, /* 黑子. */
	WHITE  /* 白子. */
} PIECE;

#define INF 0x3f3f3f3f /// 无穷大.
#define GRID_NUM 16	   /// 棋盘大小.
#define MAX_DEPTH 3	   /// 最大搜索深度, 设置为 2 运算很快, 4 很慢.

/// 状态返回代码.
typedef int STATUS;
#define TRUE 1
#define FALSE 0

/// 用于检验招法是否在棋盘上
#define inboard(x, y) (x > 0 && x < GRID_NUM && y > 0 && y < GRID_NUM)

/// 坐标结构体.
typedef struct point
{
	/// 横纵坐标.
	int x, y;
} point;

/* 声明外部变量. */
extern int chessBoard[GRID_NUM][GRID_NUM];		 /// 棋盘.
extern int piece;								 /// 玩家.
extern point feasibleMoves[MAX_DEPTH + 1][1000]; /// 可行招法
extern point currentMove[MAX_DEPTH + 1];		 /// 当前招法.
extern point bestMove;							 /// 最好招法.

#endif
