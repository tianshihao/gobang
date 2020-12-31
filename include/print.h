/**
 * @file print.h
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 输出模块头文件
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef PRINT_H_
#define PRINT_H_

#include "define.h"

/**
 * @brief 按行打印棋盘.
 * 
 */
void PrintChessBoard();

/**
 * @brief 打印非棋子的棋盘.
 * 
 * @param i 横坐标.
 * @param j 纵坐标.
 */
void PrintEdge(int i, int j);

#endif
