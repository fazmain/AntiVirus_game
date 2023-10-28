#include <iostream>

#include "Board.hpp"
#include "piece.hpp"

using namespace std;

int main() {
    Board gameboard;
    char* zero = "0";

    int location[2] = {3,4};
    piece virus(zero,location ,0, &gameboard);


    gameboard.showBackend();
    gameboard.showFrontend();
    virus.movePiece("NW", 2);
    gameboard.showBackend();
    gameboard.showFrontend();

    return 0;
}
