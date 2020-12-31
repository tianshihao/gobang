/**
 * @file main.c
 * @author 田世豪 (tianshihao@4944@126.com)
 * @brief 主函数入口
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "define.h"
#include "gameover.h"
#include "makemove.h"
#include "print.h"
#include "searchmove.h"

int main()
{
	printf("***********欢迎来到五子棋人机对弈系统***********\n");
	printf("输入：“newblack”表示电脑先手\n");
	printf("输入：“newwhite”表示电脑后手\n");
	printf("输入: “move x y”表示落子点\n");

	/* 打印棋盘. */
	PrintChessBoard();

	char input[64];
	point position;

	while (~scanf("%s", input))
	{
		/* 电脑先手. */
		if (strcmp(input, "newblack") == 0)
		{
			/* 清空屏幕. */
			system("cls");
			/* 电脑执黑子. */
			piece = BLACK;
			/* 电脑落子. */
			SearchBestMove(piece);
			/* 打印棋盘. */
			PrintChessBoard();
			/* 改变棋子颜色. */
			piece = 3 - piece;
		}
		/* 电脑后手. */
		else if (strcmp(input, "newwhite") == 0)
		{
			/* 玩家执白棋. */
			piece = WHITE;
		}
		/* 落子指令. */
		else if (input[0] == 'm')
		{
			/* 读取落子坐标. */
			scanf("%d %d", &position.x, &position.y);

			/* 如果要落子位置已经有棋子了. */
			if (chessBoard[position.x][position.y])
			{
				printf("(%d, %d) 已经有棋子了，请重新输入。\n", position.x, position.y);
				continue;
			}

			/* */
			getchar();
			/* 清空屏幕. */
			system("cls");
			/* 玩家落子. */
			MakeMove(position, piece);
			/* 打印棋盘. */
			PrintChessBoard();

			/* 如果玩家落子之后连成五子. */
			if (Gameover(position, piece))
			{
				printf("玩家赢了。\n");
				system("pause");
				break;
			}

			/* 清理屏幕. */
			system("cls");
			/* 改变棋子颜色. */
			piece = 3 - piece;
			/* 电脑落子. */
			SearchBestMove(piece);
			/* 打印棋盘. */
			PrintChessBoard();

			/* 如果电脑落子后连成五子. */
			if (Gameover(bestMove, piece))
			{
				printf("电脑赢了。\n");
				system("pause");
				break;
			}
			/* 改变棋子颜色. */
			piece = 3 - piece;
		}
		/* 什么也不做. */
		else
		{
			;
		}
	}

	return 0;
}
