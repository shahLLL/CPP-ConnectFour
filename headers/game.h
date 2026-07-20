#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "disc.h"
class Game {
    Board board;
    Disc currentPlayer;
    public:
        Game();
        void display();
        bool isOver();
        bool makeMove(uint8_t column);
};
#endif