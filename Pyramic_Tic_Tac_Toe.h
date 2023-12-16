// File name: Pyramic_Tic_Tac_Toe
// Purpose: implement for Game Pyramic_Tic_Tac_Toe
// Author: Amany Mohamed Hussein Mohamed        
// ID: 20221026
// Section: S1,S2
// Date: 15/12/2023
// Version: version 1

#ifndef PYRAMIC_TIC_TAC_TOE_H
#define PYRAMIC_TIC_TAC_TOE_H
#pragma once
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;
class Pyramic_Tic_Tac_Toe:public Board{
    public:
    Pyramic_Tic_Tac_Toe();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    
};
class RandomPlayerForPyramid:public RandomPlayer
{
    private:
        int dimension1;
    public:
        // Take a symbol and pass it to parent
        RandomPlayerForPyramid (char symbol, int dimension,int dimension1);
        // Generate a random move
        void get_move(int& x, int& y);

};
#endif