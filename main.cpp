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
    char* block = "W"; // blocker
    char* zero = "0"; // red virus
    char* one = "1"; // blue virus
    char* two = "2"; // orange virus
    char* three = "3"; // pink virus
    char* four = "4"; // dGreen virus
    char* five = "5"; //dBlue virus
    char* six = "6"; // purple virus
    char* seven = "7"; // lGreen virus
    char* eight = "8"; // yellow virus
    int location[9][2] = {
        {3, 3},
        {1, 4},
        {3, 5},
        {5, 5}
        
    };
    piece red(zero, location[0], 0, &gameboard);
   // piece blue(one, location[1], 0, &gameboard);
   // piece orange(two, location[2], 0, &gameboard);
   // piece pink(three, location[3], 0, &gameboard);
//piece dGreen(four, location[4], 0, &gameboard);
   // piece dBlue(five, location[5], 0, &gameboard);
    piece purple(six, location[1], 0, &gameboard);
    piece lGreen(seven, location[2], 1, &gameboard);
    piece yellow(eight, location[3], 3, &gameboard);
   // piece blocker(block, location[9], 0, &gameboard);

    string pieceType, direction;
    int steps;
    // running game
    while (gameRunning) {
        gameboard.showFrontend();
        cout << endl;
        cout << endl;
        cout << endl;
        gameboard.showBackend();
        cout << endl;
        cout << endl;
        cout << "Enter direction and steps:  ";
        cin >> pieceType >> direction >> steps;
        switch (pieceType[0]) {
            case '0': 
                red.movePiece(direction, steps);
                break;
            case '1':
                //blue.movePiece(direction, steps);
                break;
            case '2':
                //orange.movePiece(direction, steps);
                break; 
            case '3':
                //pink.movePiece(direction, steps);
                break;
            case '4':
                //dGreen.movePiece(direction, steps);
                break;
            case '5':
                //dBlue.movePiece(direction, steps);
                break;
            case '6':
                purple.movePiece(direction, steps);
                break;
            case '7':
                lGreen.movePiece(direction, steps);
                break;
            case '8':
                yellow.movePiece(direction, steps);
                break;
            default:
                break;
        }
        // checking if player has won
        if (red.checkVictoryCondition()) {
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
