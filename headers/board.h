#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <iostream>
#include <array>
#include "consts.h"
#include "disc.h"
#include "helper.h"

typedef uint8_t smallInt;

class Board {
    const smallInt rows = 6;
    const smallInt columns = 7;
    const smallInt winningNum = 4;
    short assigned;
    bool connect;
    std::array<std::array<Disc, 7>, 6> board;

    bool checkVertical(smallInt col);
    bool checkHorizontal(smallInt col);
    bool checkDiagonalLDUR(smallInt col);
    bool checkDiagonalLUDR(smallInt col);
    void checkConnect(smallInt col);

    public:
        Board();
        smallInt getRows();
        smallInt getColumns();
        bool add(smallInt column, Disc d);
        bool isFull();
        bool isConnect();
        void draw();
};
#endif