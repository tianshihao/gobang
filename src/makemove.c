/**
 * @file makemove.c
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 落子模块方法实现
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "makemove.h"

void MakeMove(point pos, int piece)
{
	chessBoard[pos.x][pos.y] = piece;

	return;
}

void UnMakeMove(point pos, int piece)
{
	chessBoard[pos.x][pos.y] = 0;

	return;
}
