/**
 * @file makemove.h
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 落子模块头文件
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MAKEMOVE_H_
#define MAKEMOVE_H_

#include "define.h"

/**
 * @brief 在 pos 上放上棋子 piece.
 * 
 * @param pos 棋盘位置
 * @param piece 棋子
 */
void MakeMove(point pos, int piece);

/**
 * @brief 撤销 pos 的棋子.
 * 
 * @param pos 棋盘位置.
 * @param piece 棋子.
 */
void UnMakeMove(point pos, int piece);

#endif
