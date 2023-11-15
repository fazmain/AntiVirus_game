
#ifndef DESKTOP_BOARD_HPP
#define DESKTOP_BOARD_HPP

#include <iostream>
#include <string>
using namespace std;


class Board {
private:
    string theBoard[9][9] =  {{" ", " ", " ", " ", "e", " "," ", " ", " "},
                           {" ", " ", " ", " ", "e", " "," ", " ", " "},
                           {" ", " ", " ", "e", "e", "e"," ", " ", " "},
                           {" ", " ", "e", "e", "e", "e","e", " ", " "},
                           {" ", "e", "e", "e", "e", "e","e", "e", " "},
                           {" ", " ", "e", "e", "e", "e","e", " ", " "},
                           {" ", " ", " ", "e", "e", "e"," ", " ", " "},
                           {" ", " ", " ", " ", "e", " "," ", " ", " "},
                           {" ", " ", " ", " ", " ", " "," ", " ", " "}};
public:
    Board();
    void showBackend();
    void showFrontend();
    void addPiece(int coords[3][2], char x);
    void removePiece(int coords[3][2]);
    string checkLocation(int x, int y);
};

//Initialize an empty board
Board::Board(){
}

//Show back-end version of the board (diamond-shaped version)
void Board::showBackend(){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << theBoard[i][j] << " ";
        }
        cout << endl;
    }
}

//Show front-end version of the board (square-shaped version)
void Board::showFrontend(){
    //Creating the borders of the grid
    string front[9][9];
    for(int i = 0; i <= 8; i++) {
        front[0][i] = "X";
        front[8][i] = "X";
        front[i][0] = "X";
        front[i][8] = "X";
    }
    front[0][8] = theBoard[0][4];

    //Initializing the beginning coordinates
    int brow = 3;
    int bcol = 0;
    int erow = 3;
    int ecol = 1;
    //Going through each row to replace with OG board
    for(int row = 1; row < 8; row++) {
        // Odd rows have four spots
        if ((row % 2) == 1) {
            //Odd columns locate four spots
            brow++;
            bcol++;
            int bb = brow, bo = bcol;
            for (int col = 1; col < 8; col++) {
                if ((col % 2) == 1) {
                    //Moving up the backEnd row
                    front[row][col] = theBoard[bb][bo];
                    bb = bb - 1;
                    bo = bo + 1;
                } else {
                    //Empty spaces
                    front[row][col] = ' ';
                }
            }
        } //Even rows have three spots
        else if ((row % 2) == 0) {
            //Even columns locate three spots
            erow++;
            ecol++;
            int ee = erow, eb = ecol;
            for (int col = 1; col < 8; col++) {
                if ((col % 2) == 0) {
                    //Moving up the backEnd row
                    front[row][col] = theBoard[ee][eb];
                    ee = ee - 1;
                    eb = eb + 1;
                } else {
                    //Empty spaces
                    front[row][col] = ' ';
                }
            }
        }
    }
    //Display user interface
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << front[i][j] << " ";
        }
        cout << endl;
    }

}

void Board::addPiece(int coords[3][2], char insert){
    int i = 0;
    int j = 0;
    while ((coords[i][j] != -1) && (i < 3)){
        int x;
        int y;
        x = coords[i][j];
        j++;
        y = coords[i][j];
        theBoard[x][y] = insert;
        i++;
        j--;
    }
}

void Board::removePiece(int coords[3][2]){
    int i = 0;
    int j = 0;
    while ((coords[i][j] != -1) && (i < 3)){
        int x;
        int y;
        x = coords[i][j];
        j++;
        y = coords[i][j];
        theBoard[x][y] = 'e';
        i++;
        j--;
    }
}

string Board::checkLocation(int x, int y){
    return theBoard[x][y];
}

#endif //DESKTOP_BOARD_HPP
