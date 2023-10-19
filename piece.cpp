// we have a piece class that has a type, initialLocation, and orientation
// type is a 0-9 that indicated the type/shape of piece 
// initialLocation is two ints referencing the indicy of the starting point of the piece in the 2d array
// orientation is a 0-3 that indicates the orientation of the piece


//location is SETS of coordinates that reference the location of all of the parts of the piece in the 2darray(board)
int location[3][2];




piece(int type, array initialLocation, int orientation){
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
        break;
        case 2:
            break;

    }
    board.addPiece(type, location);
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