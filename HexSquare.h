//
// Created by Mai on 11/26/2021.
//

#ifndef HEXGAME_HEXSQUARE_H
#define HEXGAME_HEXSQUARE_H

#include <iostream>
#include "GameConsts.h"
using namespace std;
class HexSquare {
public:
    //c'tor
    HexSquare():sign(Gray), on(1), left(false),right(false),top(false), bottom(false), root(){};
    //d'tor
    ~HexSquare();

    friend ostream& operator<<(ostream& out,  const HexSquare&);
    // Setters
    void setSign(int toChange);


    // getters
    bool hasBoth() const;
    int getSign() const{ return sign;}
    int getOn() const{ return on;}
private:
    void setOFF();
    friend class Board;
    int sign;
    int on;
    bool left;
    bool right;
    bool top;
    bool bottom;
    HexSquare* root;
};


#endif //HEXGAME_HEXSQUARE_H
