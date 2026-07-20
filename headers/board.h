#ifndef BOARD_H
#define BOARD_H
#include <cstdint>
#include <iostream>
#include <array>
#include "consts.h"
#include "disc.h"
#include "helper.h"
class Board {
    const uint8_t rows = 6;
    const uint8_t columns = 7;
    short assigned;
    std::array<std::array<Disc, 7>, 6> board;
    public:
        Board();
        uint8_t getRows();
        uint8_t getColumns();
        bool add(uint8_t column, Disc d);
        bool isFull();
        void draw();
};
#endif