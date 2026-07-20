#include "../headers/helper.h"
std::string draw(Disc disc) {
    if(disc == Disc::EMPTY)
        return ".";
    if(disc == Disc::RED)
        return ANSI_RED + "R" + ANSI_END;
    if(disc == Disc::YELLOW)
        return ANSI_YELLOW + "Y" + ANSI_END;
    throw std::invalid_argument("Unknown Disc Type Passed to Draw");
}