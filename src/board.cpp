#include "../headers/board.h"
using namespace std;
Board::Board() : assigned(0), board({{
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY}
    }}) {}
uint8_t Board::getColumns() { return columns; }
uint8_t Board::getRows() { return rows; }
bool Board::add(uint8_t column, Disc d) {
    column = column - 1;
    if(d == Disc::EMPTY)
        throw std::invalid_argument("Empty Disc Type Passed to Add");
    if((column >= columns) || (column < 0))
        return false;
    if(board[0][column] != Disc::EMPTY)
        return false;
    int i = rows - 1;
    while(board[i][column] != Disc::EMPTY)
        i = i - 1;
    board[i][column] = d;
    assigned = assigned + 1;
    return true;
}
bool Board::isFull() { return assigned == (rows * columns); }
void Board::draw() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            cout << drawDisc(board[i][j]) << " ";
        cout << endl;
    }
}