// we have a piece class that has a type, initialLocation, and orientation
// type is a 0-9 that indicated the type/shape of piece 
// initialLocation is two ints referencing the indicy of the starting point of the piece in the 2d array
// orientation is a 0-3 that indicates the orientation of the piece


//location is SETS of coordinates that reference the location of all of the parts of the piece in the 2darray(board)
int location[1][2];




piece(int type, array initialLocation, int orientation){
    //update location to include all spots the piece is on the board based on orrientation and initial location 
    
    board.addPiece(type, int location[][]);
}

void movePiece(int piece, string direction, int steps){
    
    if(checkMove(piece, direction, steps)){
        board.removePiece(piece);
        //update location
        switch (direction)
        {
        case "NE":
            foreach location[][]
                -1 to row
            break;
        case "NW":
            foreach location[][]
                -1 to column
            break;
        case "SE":
            foreach location[][]
                +1 to column
            break;
        case "SW":
            foreach location[][]
                +1 to row
            break;
        default:
            break;
        }
        board.addPiece(piece, location[][]);
    }else{
        throw exception("Invalid Move")
    }
    
}