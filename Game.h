//
// Created by Mai on 11/26/2021.
//

#ifndef HEXGAME_GAME_H
#define HEXGAME_GAME_H
#include "Board.h"
#include <iostream>
#include <cctype>
#include <string>

typedef struct move{
    int letter;
    int number;
}Move;




class Game {
public:
    // c'tor
    explicit Game(Board& board);
    //d'tor
    ~Game();

    //class methods
    void play();

    Move getPlayerMove();


private:
    static char turn();
    static int winFlag;
    int isvalidInput(const string& userInput);
    void parseInput(string &userInput, char& letter, int& number);
    Board& board;
};


#endif //HEXGAME_GAME_H
