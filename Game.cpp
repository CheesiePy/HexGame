//
// Created by Mai on 11/26/2021.
//

#include <cstdlib>
#include <sstream>
#include <cstring>
#include "Game.h"
using namespace std;
int Game::winFlag = 0;

char Game::turn()
{
    if(Board::getTurn()%2 == 0)
        return 'R';
    else
        return 'B';

}

void Game::play() {
    int gameKey = -1;
    while(gameKey < 0)
    {
        char player = turn();
        cout << board;
        cout << player << ':' << endl;
        Move current_move = getPlayerMove();
        board.playerMove(current_move.letter, current_move.number);
        if(current_move.number == -1 && current_move.letter == -1){
            cout << player << ": QUIT" << endl;
            winFlag++;
        }
        if(board.gameEnded())
            winFlag++;
        if( winFlag > 0)
        {
            cout << board;
            board.pushTurn(); // the turn need to be pushed once in case of a winner
            player = turn();
            cout << player << " wins the game." << endl;
            gameKey++;
        }


    }
}




Move Game::getPlayerMove() {
    int key = -1;
    char letter;
    int number = 0;
    Move move;
     // input should look like A5, A = rows and 5 is cols
    while(key < 0)
    {

        string userInput;
        cin >> userInput;
        if(userInput == "QUIT"){
            winFlag++;
            move.letter = -1;
            move.number = -1;
            return move;
        }// exit condition
        if(!isvalidInput(userInput))
        {
            wcerr << "Invalid move; the game awaits a valid move." << endl;
            continue;
        }

        parseInput(userInput,letter,number);
        key++;
    }
    move.letter = (int)letter - 64;
    move.number = number;
    return move;
}

Game::Game(Board& board):board(board){
}

Game::~Game() {}



void Game::parseInput(string &userInput, char& letter, int& number) {
    letter = toupper(userInput[0]);
    string num = userInput.substr(1);
    number = atoi(num.c_str());
}

int Game::isvalidInput(const string &userInput) {
    char ch[userInput.size() -1]; // ch is going to contain userInput without the first letter;
    strcpy(ch,userInput.c_str() + 1);

    if(!isalpha(userInput[0])) // check if first char is not a letter
        return 0;
    if(!isdigit(userInput[1])) // check if second char is not a  digit
        return 0;
    char first_letter = toupper(userInput[0]); // raise the char to upper case
    if(first_letter > 'K' || first_letter < 'A') // check for char range
        return 0;
    int num = atoi(ch); // set num as an int from the ch value;
    if(num > 11 || num < 0) // check num range
        return 0;
    return 1;
}

