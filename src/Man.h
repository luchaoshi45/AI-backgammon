//
// Created by zcx on 2023/10/19.
//

#ifndef AI_BACKGAMMON_MAN_H
#define AI_BACKGAMMON_MAN_H

#include "Chess.h"
#include <iostream>

class Man
{
public:
    Man(){
        std::cout << "Man\n";
    };
    void go();
};

#endif //AI_BACKGAMMON_MAN_H
