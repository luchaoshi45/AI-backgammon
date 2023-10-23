//
// Created by zcx on 2023/10/19.
//

#include "Man.h"

void Man::go(Chess* chess) {
    ChessPos pos;
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN) {
            if (chess->clickBoard(msg.x, msg.y, &pos)) {

                chess->set_chessMap(&pos, chees_color);
                chess->chessDown(&pos, chees_color);
                //std::cout << "ok WM_LBUTTONDOWN\n";
                break;
            }
        }
    }
}