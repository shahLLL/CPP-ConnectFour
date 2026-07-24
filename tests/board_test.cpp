#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <stdexcept>
#include "../headers/board.h"

TEST_CASE("ACCESSOR TEST CASES", "[board]") {
    Board b = Board();
    smallInt expectedRows = 6;
    smallInt expectedColumns = 7;
    REQUIRE(b.getRows() == expectedRows);
    REQUIRE(b.getColumns() == expectedColumns);
}

TEST_CASE("ADD TEST CASE #1: TEST FOR VALID INPUTS", "[board]") {
    Board b = Board();
    Disc d = Disc::RED;
    for(int i = 1; i <= b.getColumns(); i++)
        REQUIRE(b.add(i, d) == true);
}

TEST_CASE("ADD TEST CASE #2: TEST FOR INVALID INPUTS, COLUMN RANGE", "[board]") {
    Board b = Board();
    Disc d = Disc::RED;
    for(int i = -2; i < 1; i++)
        REQUIRE(b.add(i, d) == false);
    for(int i = b.getColumns() + 1; i <= b.getColumns() + 3; i++)
        REQUIRE(b.add(i, d) == false);
}

TEST_CASE("ADD TEST CASE #3: TEST FOR INVALID INPUTS, FULL COLUMN", "[board]") {
    Board b = Board();
    Disc d = Disc::YELLOW;
    for(int i = 0; i < b.getRows(); i++)
        REQUIRE(b.add(1, d) == true);
    REQUIRE(b.add(1, d) == false);
}

TEST_CASE("ADD TEST CASE #4: TEST FOR INVALID INPUTS, EMPTY DISC", "[board]") {
    Board b = Board();
    Disc d = Disc::EMPTY;
    for(int i = 1; i <= b.getColumns(); i++) {
        REQUIRE_THROWS_AS(b.add(i, d), std::invalid_argument);
        REQUIRE_THROWS_WITH(b.add(i, d), "Empty Disc Type Passed to Add");
    }
}

TEST_CASE("IS FULL TEST CASES", "[board]") {
    Board b = Board();
    Disc d = Disc::RED;
    smallInt columns = b.getColumns();
    smallInt rows = b.getRows();

    for(int i = 1; i <= columns; i++) {
        for(int j = 0; j < rows; j++) {
            REQUIRE(b.isFull() == false);
            b.add(i, d);
            d = (d == Disc::RED ? Disc::YELLOW : Disc::RED);
        }
    }

    REQUIRE(b.isFull() == true);
}

TEST_CASE("IS CONNECT TEST CASE #1: VERTICAL", "[board]") {
    Board b = Board();
    Disc redDisc = Disc::RED;
    Disc yellowDisc = Disc::YELLOW;

    SECTION("COLUMN = 1"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(1, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 2"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(2, yellowDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 3"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(3, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 4"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(4, yellowDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 5"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(5, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 6"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(6, yellowDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 7"){
        for(int i = 0; i < 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(7, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }
}

TEST_CASE("IS CONNECT TEST CASE #2: HORIZONTAL", "[board]") {
    Board b = Board();
    Disc redDisc = Disc::RED;
    Disc yellowDisc = Disc::YELLOW;

    SECTION("COLUMN = 1") {
        for(int i = 1; i <= 4; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(i, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 2") {
        for(int i = 2; i <= 5; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(i, yellowDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 3") {
        for(int i = 3; i <= 6; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(i, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 4") {
        for(int i = 4; i <= 7; i++) {
            REQUIRE(b.isConnect() == false);
            b.add(i, yellowDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 5") {
        for(int i = 5; i >= 2; i--) {
            REQUIRE(b.isConnect() == false);
            b.add(i, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 6") {
        for(int i = 6; i >= 3; i--) {
            REQUIRE(b.isConnect() == false);
            b.add(i, yellowDisc);
        }
        REQUIRE(b.isConnect() == true);
    }

    SECTION("COLUMN = 7") {
        for(int i = 7; i >= 4; i--) {
            REQUIRE(b.isConnect() == false);
            b.add(i, redDisc);
        }
        REQUIRE(b.isConnect() == true);
    }
}