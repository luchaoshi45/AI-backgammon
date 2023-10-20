//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_AI_H
#define AI_BACKGAMMON_AI_H

#include "Chess.h"
#include <iostream>

class AI
{
public:
    AI(){
        std::cout << "AI\n";
    };
    void go();
};


#endif //AI_BACKGAMMON_AI_H
