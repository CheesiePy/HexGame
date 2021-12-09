//
// Created by Mai on 11/26/2021.
//

#include "HexSquare.h"

bool HexSquare::hasBoth() const {
    if( (sign == Blue && left && right) || (sign == Red && top && bottom) ) {
        return true;
    }
    return false;
}
void HexSquare::setSign(int toChange) {
    if(sign != 0)
        return;
    sign = toChange;
}

HexSquare::~HexSquare() {}

void HexSquare::setOFF() {
    on = 0;
}

ostream &operator<<(ostream &out, const HexSquare &p) {
    if(!p.on)
    {
        out << " ";
        return out;
    }


    if (p.sign == 0)
        out << "O";
    if(p.sign == 1)
        out << "B";
    if(p.sign == 2)
        out << "R";
    return out;
}
