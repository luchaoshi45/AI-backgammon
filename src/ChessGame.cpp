//
// Created by zcx on 2023/10/19.
//

#include "ChessGame.h"
#include "include.h"


// 单个对局开始
void ChessGame::play(){

    while(True){
        man.go();
        if(chess.checkOver()){
            break;
        }
        ai.go();
        if(chess.checkOver()){
            break;
        }
    }


}