/**
 * @file searchmove.h
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 搜索模块头文件
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SEARCHMOVE_H_
#define SEARCHMOVE_H_

#include "define.h"

/**
 * @brief alpha-beta剪枝. 基于深度优先搜索. 
 * 
 * @param depth 搜索深度
 * @param alpha 最大值
 * @param beta 最小值
 * @param piece 棋子
 * @return int 
 */
int AlphaBeta(int depth, int alpha, int beta, int piece);

/**
 * @brief 得到招法，如果超时直接返回无效解。
 * 
 * @param piece 
 * @return int 
 */
int SearchBestMove(int piece);

/**
 * @brief 
 * 
 * @param depth 
 * @return int 可行招法数量
 */
int UpdateFeasibleMoves(int depth);

#endif
