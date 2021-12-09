//
// Created by Mai on 11/26/2021.
//

#include "Board.h"
int Board::turns = 1;

ostream& operator<<(ostream& out, const Board& b){
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0 ; j < (BOARD_SIZE)+i; j++) {
            if (!b.GameMatrix[i][j]->getOn()){
                out << " ";
            }else if(j == BOARD_SIZE+i-1){
                cout << *b.GameMatrix[i][j] << endl;
            }else{
                out << *b.GameMatrix[i][j] << " ";
            }


        }

    }
    return out;

}

Board::Board():GameMatrix(new HexSquare**[BOARD_SIZE]),endGame(false){
    for(int i = 0; i < BOARD_SIZE; i++)
    {
       GameMatrix[i] = new HexSquare*[(BOARD_SIZE)+i];
       for(int j = 0; j < (BOARD_SIZE)+i;j++)
       {
           GameMatrix[i][j] = new HexSquare();
           if(j < i){
               GameMatrix[i][j]->setOFF();
               continue;
           }
           GameMatrix[i][j]->root = GameMatrix[i][j]; // Create a singletone union
           if(i == j) // give the left token to all HexSQ that are in the left boarder
               GameMatrix[i][j]->left = true;
           if(j == BOARD_SIZE-1+i) // give the right token to all HexSQ in the right boarder
               GameMatrix[i][j]->right = true;
           if(i == 0) // give the Top token to all HexSQ in the Top boarder
               GameMatrix[i][j]->top = true;
           if(i == BOARD_SIZE-1) // give the Bottom token to all HexSQ in the Bottom boarder
               GameMatrix[i][j]->bottom = true;
       }
    }
}

Board::~Board() {
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE+i; j++)
            delete GameMatrix[i][j];
}

void Board::playerMove(int& y, int& x) {
    if(x == -1 && y == -1)  {
        return;
    }

    tiltCorration(x,y);

    if(GameMatrix[x][y]->getSign() != 0)
        return;
    (turns++%2==0) ? GameMatrix[x][y]->setSign(Red) : GameMatrix[x][y]->setSign(Blue);
    UnionWithNeighbours(x, y);
    endGame = GameMatrix[x][y]->hasBoth();
}

void Board::tiltCorration(int& x, int& y){
    x -= 1;
    y += x-1;

}

HexSquare* Board::findRoot(HexSquare * curr)   {

    if( curr->root == curr ) {
        return curr;
    }

    return findRoot(curr->root);

}

void Board::UnionWithNeighbours(int row, int col)  {
    // Assuming pivot hexsquare is on and already have been colored.

    HexSquare * pivot = GameMatrix[row][col];
    HexSquare * to_union = new HexSquare();


    for(int i = -1; i < 2; i++) {
        int rowSize = 10 + row;
        for(int j = -1; j < 2; j++) {
            if(i == 0 && j == 0)
                continue;
            if(i == -1 && j == 1)
                continue;
            if(i == 1 && j == -1)
                continue;
            if(row + i > 10)
                continue;
            if(row + i < 0 || col + j < 0)
                continue;
            if(col + j > rowSize)
                continue;
            if(col == rowSize && i == -1)
                continue;


            if( GameMatrix[row + i][col + j]->getSign() == pivot->getSign() )  {
                to_union = findRoot(GameMatrix[row + i][row + j]);
                to_union->root = pivot;
                if( to_union->left )    {
                    pivot->left = true;
                }
                if( to_union->right )   {
                    pivot->right = true;
                }
                if( to_union-> top )    {
                    pivot->top = true;
                }
                if( to_union->bottom ) {
                    pivot->bottom = true;
                }
            }
            else {
                continue;
            }
        }
    }
}

