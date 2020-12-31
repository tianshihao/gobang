/**
 * @file Gameover.h
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "define.h"

/**
 * @brief 判断游戏是否结束.
 * 
 * @param pos 棋盘位置. 
 * @param piece 棋子.
 * @return STATUS TRUE, 会结束.
 */
STATUS Gameover(point pos, int piece);

#endif
