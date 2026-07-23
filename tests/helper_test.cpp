#include <catch2/catch_test_macros.hpp>
#include "../headers/helper.h"
#include "../headers/disc.h"
#include "../headers/consts.h"


TEST_CASE("DRAW DISC TEST CASE #1", "[draw_disc]") {
    std::string expectedRed = ANSI_RED +"R" + ANSI_END;
    std::string expectedYellow = ANSI_YELLOW + "Y" + ANSI_END;
    REQUIRE(drawDisc(Disc::EMPTY) == ".");
    REQUIRE(drawDisc(Disc::RED) == expectedRed);
    REQUIRE(drawDisc(Disc::YELLOW) == expectedYellow);
}