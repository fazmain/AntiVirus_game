#include <iostream>
#include <string.h>

#include "Border.hpp"
#include "piece.hpp"

using namespace std;

int main() {
    Board gameboard;

    int eek[2] = {3,4};
    piece virus('0',eek ,0, &gameboard);


    gameboard.showBackend();
    gameboard.showFrontend();
    //virus.move()

    return 0;
}
