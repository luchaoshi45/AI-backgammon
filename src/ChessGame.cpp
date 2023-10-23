//
// Created by zcx on 2023/10/19.
//

#include "ChessGame.h"
#include "include.h"


// 单个对局开始
void ChessGame::play(){

    chess->init();
    ai->init(chess);
    while(True){
        man->go(chess);
        if(chess->checkOver()){
            break;
        }
        ai->go(chess);
        if(chess->checkOver()){
            break;
        }
    }


}

void ChessGame::run() {
    while (True) {
        play();
        Sleep(3000);
        //break;
        //_getch();
    }
}