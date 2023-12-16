// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "XO_25_Board.h"
using namespace std;
int main() {
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Menu of games :\n1- XO Board\n2- XO 5*5 Board\n3-cccccc\n4- aaaaaa\n";
    cout << "Enter the number of the game you want to play :\n";
    int num;
    cin >> num;
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer('o', 12);
    if (num == 1) {
        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
    } else if (num == 2) {
        GameManager x_o_game(new XO_25_Board(), players);
        x_o_game.run();
    }
    system("pause");
}
