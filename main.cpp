#include <iostream>
#include "HexSquare.h"
#include "Board.h"
#include "Game.h"

int main() {
    Board b;
    Game game(b);
    game.play();

    return 0;
}
