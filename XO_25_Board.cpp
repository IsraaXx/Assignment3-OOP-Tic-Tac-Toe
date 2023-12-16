#include "XO_25_Board.h"
#include <iostream>
#include <iomanip>
using namespace std;
XO_25_Board::XO_25_Board() {  // make our board 5*5 for this game
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool XO_25_Board::update_board(int x, int y, char mark) {  // update the board with symbol
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}

void XO_25_Board::display_board() {  // print the board
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}

bool XO_25_Board::is_winner() {  // to find the winner who has more counts than the other
    int count_x = 0, count_o = 0;
    if (n_moves != 24)           // there is no winner if the moves is not reached 24 yet
        return false;
    for (int i = 0; i <
                    n_rows; ++i) {  // loop on all the rows and then check every 3 cells in the same row comes after each other that
        for (int j = 0; j < n_cols - 2; ++j) { // has the same symbol and increment the counter if this happens
            if (board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2]) { // we stop at the column j=2 because j+1 and j+2
                if (board[i][j] ==
                    'X')      // that is the last we need to check we cant check more it will be out of range
                    count_x++;
                else if (board[i][j] == 'O')
                    count_o++;
            }
        }
    }
    for (int j = 0; j <
                    n_cols; ++j) { // loop on all the columns and then check every 3 cells in the same column comes after each other that
        for (int i = 0; i < n_rows - 2; ++i) { // has the same symbol and increment the counter if this happens
            if (board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j]) { // we stop at the row i=2 because i+1 and i+2
                if (board[i][j] ==
                    'X')         // that is the last we need to check we cant check more it will be out of range
                    count_x++;
                else if (board[i][j] == 'O')
                    count_o++;
            }
        }
    }
    for (int i = 0; i < n_rows - 2; ++i) { // check the main diagonal top left to bottom right
        for (int j = 0;
             j < n_cols - 2; ++j) { // we stop at i and j = 2 because most cell we want to check will have index 4
            if (board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2]) {  // and we get it by increment 2
                if (board[i][j] == 'X')
                    count_x++;
                else if (board[i][j] == 'O')
                    count_o++;
            }
        }
    }
    for (int i = n_rows - 1; i >= 2; --i) {  // the inverse diagonal form bottom left to top right
        for (int j = 0; j < n_cols - 2; ++j) {  // i decreases by 1 and j increases by 1 by going from bottom to top
            if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]) {
                if (board[i][j] == 'X')
                    count_x++;
                else if (board[i][j] == 'O')
                    count_o++;
            }
        }
    }

    if (count_o == count_x)
        return false;
    else if (count_o > count_x)
        cout << "Winner is : O \n";
    else
        cout <<"Winner is : X \n";
    return true;
}

bool XO_25_Board::is_draw() {
    return (n_moves == 24 && !is_winner());
}

bool XO_25_Board::game_is_over() {
    return n_moves >= 24;
}