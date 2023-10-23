//
//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_CHESSGAME_H
#define AI_BACKGAMMON_CHESSGAME_H


#include "Man.h"
#include "AI.h"
#include "Chess.h"
#include <iostream>

class ChessGame
{
public:
    ChessGame(){
        chess = new Chess(13-1, 6890, 800, {481,541}, {6412,6413}, 40);
        chess->init();
        
        ai = new AI();
        ai->init(chess);
        man = new Man;  // 分配内存 调用构造函数

        std::cout << "ChessGame\n";
    };
    ~ChessGame() {
        delete man;
        delete ai;
        delete chess;

        std::cout << "~ChessGame\n";
    };

    void play();
    void run();
    

private:
    Man *man; // 声明变量
    AI *ai;
    Chess *chess;
};


#endif //AI_BACKGAMMON_CHESSGAME_H
