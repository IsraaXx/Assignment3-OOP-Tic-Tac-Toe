// File name: Pyramic_Tic_Tac_Toe
// Purpose: implement for Game Pyramic_Tic_Tac_Toe
// Author: Amany Mohamed Hussein Mohamed        
// ID: 20221026
// Section: S1,S2
// Date: 15/12/2023
// Version: version 1


#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
#include "Pyramic_Tic_Tac_Toe.h"
using namespace std;
Pyramic_Tic_Tac_Toe::Pyramic_Tic_Tac_Toe()
{
   n_rows =3;
   n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] =' ';
   }
}

bool Pyramic_Tic_Tac_Toe::update_board(int x, int y, char mark) //if move is valid and put it on board Return true within board boundaries in empty cell otherwise Return false 
{
   if(((x==0&&y==2)||(x==1&&y==1)||(x==1&&y==2)||(x==1&&y==3)||(x==2&&y==0)||(x==2&&y==1)||(x==2&&y==2)||(x==2&&y==3)||(x==2&&y==4))&&board[x][y]==' '){
   board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}
void Pyramic_Tic_Tac_Toe::display_board()  // Display the board for the Pyramid shape and the pieces on it
{
    cout << setw(25) << "|(0, 2) " << board[0][2] << '|' << endl;
    cout << setw(28) << "----------" << endl;
    cout << "         |(1, 1) " << board[1][1] << "|(1, 2) " << board[1][2] << "|(1, 3) " << board[1][3] << '|' <<  endl;
    cout << "         ----------------------------" << endl;
    cout << "|(2, 0) " << board[2][0] << "|(2, 1) " << board[2][1] << "|(2, 2) " << board[2][2] << "|(2, 3) " << board[2][3] << "|(2, 4) " << board[2][4] << '|' << endl;
    cout << "----------------------------------------------" << endl;
}

bool Pyramic_Tic_Tac_Toe::is_winner() //Returns true if there is any winner  either X or O
{
    if(board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[0][2]!=' ')
    {
      return true;
    }
    else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' ')
    {
      return true;
    }
    else if(board[0][2]==board[1][3]&&board[1][3]==board[2][4]&&board[0][2]!=' ')
    {
      return true;
    }
    else if(board[1][1]==board[1][2]&&board[1][2]==board[1][3]&&board[1][1]!=' ')
    {
      return true;
    }
    else if(board[2][0]==board[2][1]&&board[2][1]==board[2][2]&&board[2][0]!=' ')
    {
      return true;
    }
    else if(board[2][1]==board[2][2]&&board[2][2]==board[2][3]&&board[2][1]!=' ')
    {
      return true;
    }
    if(board[2][2]==board[2][3]&&board[2][3]==board[2][4]&&board[2][2]!=' ')
    {
      return true;
    }
    return false;
}
bool Pyramic_Tic_Tac_Toe::is_draw()
{
    return (n_moves == 9 && !is_winner());
}
bool Pyramic_Tic_Tac_Toe::game_is_over()
{
    return n_moves >= 9;
}

RandomPlayerForPyramid::RandomPlayerForPyramid(char symbol, int dimension, int dimension1):RandomPlayer(symbol,dimension)//to add the new dimension =5
{
    this->dimension1 = dimension1;
    
}

void RandomPlayerForPyramid::get_move(int &x, int &y)
{
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension1);
}
