#ifndef SRC_XO_25_BOARD_H
#define SRC_XO_25_BOARD_H
#include <iostream>
#include"../include/BoardGame_Classes.hpp"
class XO_25_Board :public Board{
public:
    XO_25_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

};
#endif //SRC_XO_25_BOARD_H
