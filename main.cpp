#include <iostream>
#include <string>
#include "headers/board.h"
#include "headers/game.h"

using namespace std;

int main() {
    cout << ANSI_YELLOW << "WELCOME TO CPP CONNECT-4" << ANSI_END << endl;
    cout << ANSI_RED << "GOOD LUCK!" << ANSI_END << endl;
    Board b = Board();
    Game g = Game();
    b.add(1, Disc::RED);
    b.add(2, Disc::RED);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.draw();
    cout << endl;
    g.display();
    return 0;
}