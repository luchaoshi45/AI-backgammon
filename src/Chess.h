//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_CHESS_H
#define AI_BACKGAMMON_CHESS_H
#include <iostream>
#include <graphics.h> // easyx
#include <vector> // easyx

typedef enum {
    CHESS_BLACK = 0,   // 黑方
    CHESS_WHITE = 1    // 白方
} chess_kind_t;

struct ChessPos {
    int row;
    int col;
};

class Chess{
public:
    // 棋盘的初始化：加载棋盘的图片资源，初始化棋盘的相关数据
    Chess(){
        std::cout << "Chess\n";
    };

    // 判断在指定坐标(x,y)位置，是否是有效点击
    // 如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
    bool clickBoard(int x, int y, ChessPos* pos);

    // 在棋盘的指定位置（pos）, 落子（kind）
    void chessDown(ChessPos* pos, chess_kind_t kind);

    // 获取棋盘的大小（13线、15线、19线）
    int getGradeSize();

    // 获取指定位置是黑棋，还是白棋，还是空白
    int getChessData(ChessPos* pos);
    int getChessData(int row, int col);

    // 判断棋局是否结束
    bool checkOver();
private:
    IMAGE chessBlackImg;
    IMAGE chessWhiteImg;
    int gradSize;
    int margin_x;
    int margin_y;
    float chessSize;

    std::vector< std::vector<int> >chessMap;
    bool playerFlag;  // False CHESS_BLACK = 0 黑方    True CHESS_WHITE = 1  白方
};


#endif //AI_BACKGAMMON_CHESS_H
