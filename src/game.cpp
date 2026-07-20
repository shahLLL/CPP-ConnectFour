#include "../headers/game.h"
using namespace std;
Game::Game(): board(), currentPlayer(Disc::RED) {}
void Game::display() {
    board.draw();
    for(int i = 0; i < board.getColumns(); i++)
        cout << i + 1 << " ";
    cout << endl;
    cout << endl << "TURN: " << drawDisc(currentPlayer) << endl;
}
bool Game::isOver() { return board.isFull(); }
bool Game::makeMove(uint8_t column) {
    if(!board.add(column, currentPlayer))
        return false;
        
    currentPlayer = (currentPlayer == Disc::RED) ? Disc::YELLOW : Disc::RED;
    return true;
}