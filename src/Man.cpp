//
// Created by zcx on 2023/10/19.
//

#include "Man.h"

void Man::go(Chess* chess) {
    ChessPos pos;
    while (true){
        volatile ExMessage msg = getmessage(EX_MOUSE); // 一定要清空消息队列
        if (msg.message == WM_LBUTTONDOWN) {
            if (chess->clickBoard(msg.x, msg.y, &pos)) {

                chess->set_chessMap(&pos, chees_color);
                chess->chessDown(&pos, chees_color);
                break;
            }
        }

    }
}