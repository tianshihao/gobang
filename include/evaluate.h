/**
 * @file evaluate.h
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 估值模块头文件
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EVALUATE_H_
#define EVALUATE_H_

#include "define.h"

/**
 * @brief 估值
 * 
 * @param p 
 * @param piece 
 * @return int 
 */
int Evaluate(point p, int piece);

/**
 * @brief 
 * 
 * @param p 
 * @param player1 
 * @param player2 
 * @return int 
 */
int evaluate(point p, int player1, int player2);

/**
 * @brief Get the Line object
 * 
 * @param p 
 * @param i 
 * @param j 
 * @return int 
 */
int GetLine(point p, int i, int j);

#endif
