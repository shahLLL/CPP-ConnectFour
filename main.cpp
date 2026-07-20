#include <iostream>
#include <string>
#include "headers/board.h"

using namespace std;

int main() {
    cout << "WELCOME TO CPP CONNECT-4, GOOD LUCK!" << endl;
    Board b = Board();
    b.add(1, Disc::RED);
    b.add(2, Disc::RED);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.draw();
    return 0;
}