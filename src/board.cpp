#include "../headers/board.h"

using namespace std;

// Constructor
Board::Board() : assigned(0), board({{
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY}
    }}) {}

// Accessors
uint8_t Board::getColumns() { return columns; }
uint8_t Board::getRows() { return rows; }

// Function that adds a Disc to the board. Returns true if move was successful, false otherwise.
bool Board::add(uint8_t column, Disc d) {
    // Decrement to account for zero indexing
    column = column - 1;
    
    // Validate move
    if(d == Disc::EMPTY)
        throw std::invalid_argument("Empty Disc Type Passed to Add");
    if((column >= columns) || (column < 0))
        return false;
    if(board[0][column] != Disc::EMPTY)
        return false;
    
    // Attempt move.
    int i = rows - 1;
    while(board[i][column] != Disc::EMPTY)
        i = i - 1;
    board[i][column] = d;
    assigned = assigned + 1;
    return true;
}

// Returns true if there are no more spots in the board.
bool Board::isFull() { return assigned == (rows * columns); }

// Returns a string, representing the current state of the Board.
void Board::draw() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            cout << drawDisc(board[i][j]) << " ";
        cout << endl;
    }
}