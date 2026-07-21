#include "../headers/game.h"

using namespace std;

// Constructor
Game::Game(): board(), currentPlayer(Disc::RED) {}

// This function returns a String representing the current state of the game.
void Game::display() {
    board.draw();
    for(int i = 0; i < board.getColumns(); i++)
        cout << i + 1 << " ";
    cout << endl;
    cout << endl << "TURN: " << drawDisc(currentPlayer) << endl;
}

// Returns boolean indicating if the game is complete.
bool Game::isOver() { return board.isFull(); }

// This function executes a move provided by the player by updating the board and changing current player/turn.
bool Game::makeMove(uint8_t column) {
    if(!board.add(column, currentPlayer))
        return false;
        
    currentPlayer = (currentPlayer == Disc::RED) ? Disc::YELLOW : Disc::RED;
    return true;
}