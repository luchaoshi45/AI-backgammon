//
// Created by zcx on 2023/10/19.
//

#include "ChessGame.h"
#include "include.h"


// 单个对局开始
void ChessGame::play(){

    chess->init();
    ai->init(chess);
    flushmessage(); // 清空消息队列
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

    }
}