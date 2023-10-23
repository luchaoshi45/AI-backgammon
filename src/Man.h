//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_MAN_H
#define AI_BACKGAMMON_MAN_H

#include "Chess.h"
#include <iostream>

class Man
{
private:
    chess_kind_t chees_color;  // False CHESS_BLACK = 0 ºÚ·½    True CHESS_WHITE = 1  °×·½
public:
    Man(){
        chees_color = CHESS_BLACK;
        std::cout << "Man\n";
    };
    ~Man() {
        std::cout << "~Man\n";
    };
    void go(Chess* chess);
};

#endif //AI_BACKGAMMON_MAN_H
