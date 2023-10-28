#include <iostream>

#include "Board.hpp"
#include "piece.hpp"

using namespace std;

int main() {
    Board gameboard;

    int location[2] = {3,4};
    piece virus('0',location ,0, &gameboard);


    gameboard.showBackend();
    gameboard.showFrontend();
    virus.movePiece("NW", 2);
    gameboard.showBackend();
    gameboard.showFrontend();
    cout << virus.getType() << endl;

    return 0;
}
