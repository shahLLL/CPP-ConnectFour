#include "../headers/game.h"
using namespace std;
Game::Game(): board(), currentPlayer(Disc::RED) {}
void Game::display() {
    board.draw();
    cout << endl << "TURN: " << drawDisc(currentPlayer) << endl;
}