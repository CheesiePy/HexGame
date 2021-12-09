//
// Created by Mai on 11/26/2021.
//

#ifndef HEXGAME_BOARD_H
#define HEXGAME_BOARD_H
#define BOARD_SIZE 11
#include <iostream>
#include "HexSquare.h"

class Board {
public:
    //c'tor
    Board();
    //d'tor
    ~Board();

    friend ostream& operator<<(ostream& out, const Board& b);

    // class methods
    HexSquare * findRoot(HexSquare * curr);
    void playerMove(int& x, int& y);
    static int getTurn(){return turns;};
    void UnionWithNeighbours(int row, int col);
    bool gameEnded() const  { return endGame; }
    void pushTurn(){turns++;}

private:
    void tiltCorration(int& x, int& y);
    HexSquare*** GameMatrix;
    static int turns;
    bool endGame;
};


#endif //HEXGAME_BOARD_H
