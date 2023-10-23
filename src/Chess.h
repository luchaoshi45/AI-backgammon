//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_CHESS_H
#define AI_BACKGAMMON_CHESS_H
#include <iostream>
#include <graphics.h> // easyx
#include <vector> // easyx
#include <map> // easyx
#include <mmsystem.h> // easyx
#pragma comment(lib, "winmm.lib")
#include "include.h"
#include <math.h>
#include <conio.h>
#include<Windows.h>

typedef enum {
    CHESS_NULL = -1,
    CHESS_BLACK = 0,   // 黑方
    CHESS_WHITE = 1    // 白方
} chess_kind_t;

struct ChessPos {
    int row;
    int col;
};
typedef struct {
    float x;
    float y;
}xypos;

class Chess{
public:
    Chess() {
        std::cout << "Chess\n";
    };
    // 棋盘的初始化：加载棋盘的图片资源，初始化棋盘的相关数据
    Chess(int grade_num, int win_init_size, int win_resize, 
        xypos margin, xypos end, float chess_size){
        this->grade_num = grade_num;

        this->win_init_size = win_init_size;
        this->win_resize = win_resize;
        factor = (float)win_init_size / win_resize;

        this->margin.x = margin.x / factor;
        this->end.x = end.x / factor;
        this->margin.y = margin.y / factor;
        this->end.y = end.y / factor;

        this->grade_size.x = (this->end.x - this->margin.x) / grade_num;
        this->grade_size.y = (this->end.y - this->margin.y) / grade_num;
        this->chess_size = chess_size;
        
        std::cout << "Chess\n";
    };
    ~Chess() {
        std::cout << "~Chess\n";
    };
    void chessMap_pad_null() {
        std::vector<int> tmp;
        for (int i = 0; i < grade_num+1; i++) {
            tmp.push_back(CHESS_NULL);
        }
        for (int i = 0; i < grade_num+1; i++) {
            chessMap.push_back(tmp);
        }
    }
    void init() {
        initgraph(win_resize, win_resize);
        loadimage(0, "./res/img/chess/chess_13.png", win_resize, win_resize);
        //mciSendString("open ./res/music/chun_shan_yue.mp3 alias BGM1", 0, 0, 0);
        mciSendString("open ./res/music/llusionary_Daytime.mp3 alias BGM1", 0, 0, 0);
        mciSendString("play BGM1 repeat", 0, 0, 0);

        mciSendString("open ./res/music/chess/chess.mp3 alias sfx_hit", NULL, 0, NULL);

        loadimage(&chessBlackImg, "./res/img/piece/black.png", chess_size, chess_size, true);
        loadimage(&chessWhiteImg, "./res/img/piece/white.png", chess_size, chess_size, true);
        
        chessMap_pad_null();
    }
    void chessDown_music() {
        int b = mciSendString("play sfx_hit from 1000", NULL, 0, NULL);
    }
    void vector_man() {
        mciSendString("stop BGM1", 0, 0, 0);
        mciSendString("play ./res/music/over/vector.wav", 0, 0, 0);
        loadimage(0, "./res/img/over/vector.png", 1300, 700);
    }
    void vector_ai() {
        mciSendString("stop BGM1", 0, 0, 0);
        mciSendString("play ./res/music/over/fail.wav", 0, 0, 0);

        loadimage(0, "./res/img/over/vector.png", 1300, 700);
    }

    // 判断在指定坐标(x,y)位置，是否是有效点击
    // 如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
    bool clickBoard(int x, int y, ChessPos* pos);

    // 在棋盘的指定位置（pos）, 落子（kind）
    void set_chessMap(ChessPos* pos, chess_kind_t kind);
    // 在棋盘的指定位置（pos）, 落子（kind）
    void chessDown(ChessPos* pos, chess_kind_t kind);

    // 获取棋盘的大小（13线、15线、19线）
    int get_grade_num();

    // 获取指定位置是黑棋，还是白棋，还是空白
    int getChessData(ChessPos* pos);
    int getChessData(int row, int col);

    // 判断棋局是否结束
    bool checkWin();
    bool checkOver();
    
private:
    IMAGE chessBlackImg;
    IMAGE chessWhiteImg;

    int win_init_size; // 棋盘原始大小
    int win_resize; // 棋盘resize大小
    float factor;
    int grade_num; // 网格数量 默认13-1

    xypos margin; // 起始页边距
    xypos end; // 结束页边距
    xypos grade_size; // 网格大小

    float chess_size; // 棋子大小

    std::vector< std::vector<int> >chessMap;

    ChessPos lastPos; //最近落子位置, Chess的private数据成员
    chess_kind_t playerFlag;
    
};

static void putimagePNG(int x, int y, IMAGE* picture); //x为载入图片的X坐标，y为Y坐标

#endif //AI_BACKGAMMON_CHESS_H
