#include "../headers/board.h"

using namespace std;

// Constructor
Board::Board() : assigned(0), connect(false), board({{
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY},
        {Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY, Disc::EMPTY}
    }}) {}

// Accessors
smallInt Board::getColumns() { return columns; }
smallInt Board::getRows() { return rows; }

// Function that adds a Disc to the board. Returns true if move was successful, false otherwise.
bool Board::add(smallInt column, Disc d) {
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

    // Check for Connection and Return
    checkConnect(column);
    return true;
}

// Returns true if there are no more spots in the board.
bool Board::isFull() { return assigned == (rows * columns); }

// Returns true if there is a connection in the board.
bool Board::isConnect() { return connect; }

// Returns a string, representing the current state of the Board.
void Board::draw() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            cout << drawDisc(board[i][j]) << " ";
        cout << endl;
    }
}

// Checks for a vertical match given a column (based on last move). Returns true if found, false otherwise.
bool Board::checkVertical(smallInt col) {
    smallInt row = 0;
    smallInt counter = 0;
    Disc measure = Disc::EMPTY;

    while((row < rows) && (board[row][col] == measure))
        row = row + 1;
    
    if(row < rows)
        measure = board[row][col];
    
    while(row < rows) {
        if(board[row][col] == measure) {
            counter = counter + 1;
        } else {
            counter = 1;
            measure = board[row][col];
        }

        if(counter == winningNum)
            return true;
        
        row = row + 1;
    }

    return false;
}

bool Board::checkHorizontal(smallInt col) {
    return false;
}

bool Board::checkDiagonalLDUR(smallInt col) {
    return false;
}

bool Board::checkDiagonalLUBR(smallInt col) {
    return false;
}

void Board::checkConnect(smallInt col) {
    if(checkVertical(col))
        connect = true;
    if(checkHorizontal(col))
        connect = true;
    if(checkDiagonalLDUR(col))
        connect = true;
    if(checkDiagonalLUBR(col))
        connect = true;
}

