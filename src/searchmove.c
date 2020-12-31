/**
 * @file searchmove.c
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 搜索模块方法实现
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "searchmove.h"
#include "evaluate.h"
#include "makemove.h"

int AlphaBeta(int depth, int alpha, int beta, int piece)
{
	int value = 0;

	if (depth == 0)
	{
		return Evaluate(currentMove[depth + 1], piece);
	}

	/* 每次执行剪枝都要更新可行招法. */
	int num = UpdateFeasibleMoves(depth);

	for (int i = 0; i < num; i++)
	{
		/* 获取可执行招法之一. */
		currentMove[depth] = feasibleMoves[depth][i];
		/* 执行这一招法. */
		MakeMove(currentMove[depth], piece);
		/**
		 * @brief 递归. 3 - piece 表示棋子交替考虑, 即 Max 层和 Min 层. 默认
		 * 只有电脑会使用 Alpha-Beta 剪枝搜索, 而电脑总执黑子
		 */
		value = -AlphaBeta(depth - 1, -beta, -alpha, 3 - piece);
		/* 撤销这一招法. */
		UnMakeMove(currentMove[depth], piece);

		if (value > alpha)
		{
			if (depth == MAX_DEPTH)
			{
				bestMove = feasibleMoves[MAX_DEPTH][i];
			}
			// alpha+beta剪枝点
			if (value >= beta)
			{
				return beta;
			}
			alpha = value;
		}
	}

	return alpha;
}

int SearchBestMove(int piece)
{
	//这里是AlphaBeta的第一层
	AlphaBeta(MAX_DEPTH, -INF, INF, piece);
	/* 执行最好招法. */
	MakeMove(bestMove, piece);

	return 0;
}

int UpdateFeasibleMoves(int depth)
{
	/// 可行招法数目.
	int feasibleMovesNum = 0;

	/* 遍历棋盘寻找可落子位置. */
	for (int i = 1; i < GRID_NUM; i++)
	{
		for (int j = 1; j < GRID_NUM; j++)
		{
			/* 如果棋盘上某点没有落子. */
			if (chessBoard[i][j] == BLANK)
			{
				point pos;
				pos.x = i;
				pos.y = j;

				feasibleMoves[depth][feasibleMovesNum++] = pos;
			}
		}
	}

	return feasibleMovesNum;
}
