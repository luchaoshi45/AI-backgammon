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
        std::cout << "ChessGame\n";
    };
    void play();

private:
    Man man;
    AI ai;
    Chess chess;
};


#endif //AI_BACKGAMMON_CHESSGAME_H
