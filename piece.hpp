#ifndef PIECE_HPP
#define PIECE_HPP

// we have a piece class that has a type, initialLocation, and orientation
// type is a 0-9 that indicated the type/shape of piece 
// initialLocation is two ints referencing the indicy of the starting point of the piece in the 2d array
// orientation is a 0-3 that indicates the orientation of the piece
#include <exception>
#include <string.h>
#include "Board.hpp"
using namespace std;

class piece 
{

    //location is SETS of coordinates that reference the location of all of the parts of the piece in the 2darray(board)
    public:
        int location[3][2];
        // add a board object to the piece class
        Board board;
    private:
        char type;
        int initialLocation[2];
        int orientation;
};   
    // constructor for piece
    piece::piece(char type, int initialLocation[2], int orientation){
        //update location to include all spots the piece is on the board based on orrientation and initial location 
    /*
    - W: Blocker, a piece that takes up a single space and can not be moved 1.2.10
    - 0: Red Virus orrientation: 0=down 1=right 2=up 3=left
    - 1: Blue Virus orrientation: 0=down 1=right 2=up 3=left
    - 2: Orange Virus 1.2.3
    - 3: Pink Virus 1.2.4
    - 4: Dark Green Virus 1.2.5
    - 5: Blue Virus 1.2.6
    - 6: Purple Virus 1.2.7
    - 7: Light Green Virus 1.2.8
    - 8: Yellow Virus 1.2.9*/
        location[0][0] = initialLocation[0];
        location[0][1] = initialLocation[1];
        switch (type)
        {
            case 0 || 1:
                switch (orientation)
                {
                case 0:
                    location[1][0] = initialLocation[0] + 1;
                    location[1][1] = initialLocation[1];
                break;
                case 1:
                    location[1][0] = initialLocation[0];
                    location[1][1] = initialLocation[1] + 1;
                break;
                case 2:
                    location[1][0] = initialLocation[0] - 1;
                    location[1][1] = initialLocation[1];
                break;
                case 3:
                    location[1][0] = initialLocation[0];
                    location[1][1] = initialLocation[1] - 1;
                break;
                }
            break;
        }
        board.addPiece(location, type);
    }

    // method to move the piece
    void piece::movePiece(string direction, int steps){
    
        if(isValidMove(direction, steps)){
            board.removePiece(location);
            //update location
            if(direction.compare("NE") == 0){
                for(int i = 0; i < 3; i++){//up
                    location[i][0] = location[i][0] + steps;
                }
            } else if(direction.compare("NW")==0){//left
                for(int i = 0; i < 3; i++){
                    location[i][1] = location[i][1] - steps;
                }
            } else if(direction.compare("SE")==0){//right
                for(int i = 0; i < 3; i++){
                    location[i][1] = location[i][1] + steps;
                }
            } else if(direction.compare("SW")==0){//down
                for(int i = 0; i < 3; i++){
                    location[i][0] = location[i][0] - steps;
                }
            }

            board.addPiece(location, type);
            if(type == 0){
                if(checkVictoryCondition()){
                    cout << "Victory" << endl;
                //throw exception("Victory");
                }
            }
        } else{
            //throw exception("Invalid Move");
            cout << "Invalid Move" << endl;
        }
    }


    // method to check victory condition
    bool piece::checkVictoryCondition(){
        //check if red virus is in the appropriate location
        if ((location[0][0] == 0 && location[0][1] == 5) || (location[1][0] == 0 && location[1][1] == 5)){
            return true;
        } else {
            return false;
        }
    }

    bool isValidMove(string direction, int steps){
        // always return true
        return true;
    bool piece::isValidMove(string direction, int steps){
    }

#endif