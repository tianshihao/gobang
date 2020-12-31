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
 * @brief 
 * 
 * @param pos 
 * @param piece 
 */
void MakeMove(point pos, int piece);

/**
 * @brief 
 * 
 * @param node 
 * @param piece 
 */
void UnMakeMove(point node, int piece);

#endif
