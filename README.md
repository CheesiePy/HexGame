# Hex Game

## Overview

This is a C++ implementation of the Hex Game, a two-player strategy board game played on a hexagonal grid. The project consists of several classes that work together to create and manage the game.

## Game Rules

The Hex Game is played on an 11x11 hexagonal grid. Players take turns marking a cell on the board with their respective color. The goal is to form a connected path of their color from one side of the board to the opposite side.

## Classes

### 1. `Board`

- Manages the game board, including the grid of `HexSquare` cells.
- Handles player moves, union operations, and checks for game end conditions.

### 2. `HexSquare`

- Represents a single cell on the game board.
- Keeps track of its state (color, status, borders), and handles union-find operations.

### 3. `Game`

- Orchestrates the gameplay.
- Alternates turns between players, validates moves, and checks for a winning condition.

## Running the Game

Compile and run the `main.cpp` file to start the game. Follow the on-screen prompts to make moves. Players input their moves using a combination of a letter and a number (e.g., A5).

To quit the game at any time, enter "QUIT" when prompted for a move.

## Compilation and Execution

To compile the game, use the following command:

```bash
g++ main.cpp Board.cpp HexSquare.cpp Game.cpp -o hex_game
```

Then, run the executable:

```bash
./hex_game
```
## Additional Notes
1. The project uses the C++ programming language and adheres to the C++11 standard.
2. Input validation is in place to ensure valid moves and prevent invalid input. 
3. The game keeps track of the current turn and displays the winner when the game ends.
