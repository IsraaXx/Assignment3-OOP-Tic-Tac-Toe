cmake_minimum_required(VERSION 3.24)
project(src)
set(CMAKE_CXX_STANDARD 14)
add_executable(src
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        X_O_App.cpp
        X_O_Board.cpp
        XO_25_Board.cpp
        ../include/BoardGame_Classes.hpp ../include/BoardGame_Classes.hpp ../include/BoardGame_Classes.hpp XO_25_Board.h)
