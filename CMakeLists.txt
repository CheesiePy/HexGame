cmake_minimum_required(VERSION 3.19)
project(HexGame)

set(CMAKE_CXX_STANDARD 98)

add_executable(HexGame main.cpp Game.cpp Game.h HexSquare.cpp HexSquare.h Board.cpp Board.h GameConsts.h)