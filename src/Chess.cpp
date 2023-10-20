//
// Created by zcx on 2023/10/19.
//

#include "Chess.h"

// 判断在指定坐标(x,y)位置，是否是有效点击
// 如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
bool Chess::clickBoard(int x, int y, ChessPos* pos){

	return 0;
}

// 在棋盘的指定位置（pos）, 落子（kind）
void Chess::chessDown(ChessPos* pos, chess_kind_t kind){

}

// 获取棋盘的大小（13线、15线、19线）
int Chess::getGradeSize(){
	
	return 0;
}

// 获取指定位置是黑棋，还是白棋，还是空白
int Chess::getChessData(ChessPos* pos){

	return 0;
}
int Chess::getChessData(int row, int col){

	return 0;
}

// 判断棋局是否结束
bool Chess::checkOver(){

	return 0;
}
