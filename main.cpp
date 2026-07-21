#include <iostream>
#include <string>
#include "headers/board.h"
#include "headers/game.h"

using namespace std;

// This function prints the Game Into Message
void displayIntro() {
    cout << ANSI_YELLOW << "WELCOME TO CPP CONNECT-4" << ANSI_END << endl;
    cout << ANSI_RED << "GOOD LUCK!" << ANSI_END << endl;
    Board b = Board();
    b.add(1, Disc::RED);
    b.add(2, Disc::RED);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.draw();
    cout << endl;
}

// This function executes the Main Game Loop
void executeGameLoop() {
    Game g = Game();
    while(!g.isOver()) {
        g.display();
        int col;
        cout << "ENTER MOVE: ";
        cin >> col;
        g.makeMove(static_cast<uint8_t>(col));
    }
}

// Main
int main() {
    // Display Intro
    displayIntro();

    // Game Loop
    executeGameLoop();

    return 0;
}