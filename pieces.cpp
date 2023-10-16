// we have a class called piece that has a type, initialLocation, and orientation
// type is an integer 0-9 that indicated the type/shape of piece
// initialLocation is the location of the starting point of the piece in a 2d array (8x8)
// orientation is the orientation of the piece (0-3)
#include <iostream>

using namespace std;

class Piece {
public:
    // constructor for piece
    Piece(int type, pair<int, int> initialLocation, int orientation){
        this->type = type;
        this->initialLocation = initialLocation;
        this->orientation = orientation;
    }
    
    // method to move the piece
    bool isValidMove(string direction, int steps, board board) const {
        pair<int, int> currentLocation = initialLocation;
        int currentOrientation = orientation;
        
        // update currentLocation based on direction and steps
        if (direction == "up") {
            currentLocation.first -= steps;
        } else if (direction == "down") {
            currentLocation.first += steps;
        } else if (direction == "left") {
            currentLocation.second -= steps;
        } else if (direction == "right") {
            currentLocation.second += steps;
        }
        
        // check if new location is within board bounds
        if (currentLocation.first < 0 || currentLocation.first >= board.size() ||
            currentLocation.second < 0 || currentLocation.second >= board[0].size()) {
            return false;
        }
        
        // check if new location overlaps with another piece
        for (const auto& piece : board) {
            if (piece.getInitialLocation() == currentLocation) {
                return false;
            }
        }
        
        return true;
    }
    
    void movePiece(string direction, int steps, board board){
        if (isValidMove(direction, steps, board)) {
            // update initialLocation based on direction and steps
            if (direction == "up") {
                initialLocation.first -= steps;
            } else if (direction == "down") {
                initialLocation.first += steps;
            } else if (direction == "left") {
                initialLocation.second -= steps;
            } else if (direction == "right") {
                initialLocation.second += steps;
            }
        } else {
            cout << "Invalid move" << endl;
        }
    }
    

    int getType() const { return type; }
    pair<int, int> getInitialLocation() const { return initialLocation; }
    int getOrientation() const { return orientation; }

private:
    int type;
    pair<int, int> initialLocation;
    int orientation;

};