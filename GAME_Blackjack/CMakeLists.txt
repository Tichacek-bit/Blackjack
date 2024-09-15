cmake_minimum_required(VERSION 3.28)
project(GAME_Blackjack)

set(CMAKE_CXX_STANDARD 23)

add_executable(GAME_Blackjack main.cpp
        Blackjack.cpp
        Blackjack.h)
