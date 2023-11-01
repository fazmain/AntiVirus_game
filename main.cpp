#include <iostream>

#include "Board.hpp"
#include "piece.hpp"

using namespace std;


int main() {
    // game state
    bool gameRunning = true;
    // creating game board
    Board gameboard;
    // creating virus piece
    char* zero = "0";
    int location[2] = {3,4};
    piece virus(zero, location ,0, &gameboard);

    string pieceType, direction;
    int steps;
    // running game
    while (gameRunning) {
        gameboard.showFrontend();
        cout << endl;
        cout << "Enter direction and steps:  ";
        cin >> pieceType >> direction >> steps;
        switch (pieceType[0]) {
            case '0':
                virus.movePiece(direction, steps);
                break;
            default:
                break;
        }
        // checking if player has won
        if (virus.checkVictoryCondition()) {
            gameRunning = false;
        }
        // if q key is pressed, the game quits
        if (direction.compare("q") == 0) {
            cout << endl;
            cout << endl;
            cout << "*********************" << endl;
            cout << "**   YOU HAVE QUIT **" << endl;
            cout << "*********************" << endl;
            cout << endl;
            cout << endl;
            gameRunning = false;
        }
    }
   

    return 0;
}
