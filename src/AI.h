//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_AI_H
#define AI_BACKGAMMON_AI_H

#include "Chess.h"
#include <iostream>

class AI
{
private:
    std::vector<std::vector<int>> scoreMap;
    chess_kind_t chees_color;  // False CHESS_BLACK = 0 黑方    True CHESS_WHITE = 1  白方
    ChessPos think(Chess* chess);  //private权限
    void calculateScore(Chess* chess);
    
public:
    AI(){
        chees_color = CHESS_WHITE;
        std::cout << "AI\n";
    };
    ~AI() {
        std::cout << "~AI\n";
    };
    void init(Chess* chess);
    void go(Chess* chess);
};


#endif //AI_BACKGAMMON_AI_H
