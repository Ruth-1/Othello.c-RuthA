//
// Created by Ruth on 27/04/2021.
//

#ifndef OTHELLO_BOARDCHANGES_H
#define OTHELLO_BOARDCHANGES_H
#define X 8
#define Y 8
//struct declarations
struct boardSet{//holds the board information
    char board[X][Y];
};

struct boardMove{//takes a move from a player and the player information
    int row;
    int col;
    char player;
};
struct boardSet *setBoard();//initializes the board
struct boardMove *getMove(int turn,struct boardSet *current);//gets move from player
struct boardSet *checkMove (struct boardSet *current,struct boardMove move);//function that checks if move is valid
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection);//checks if a
// move is valid and if it is,flips the corresponding discs


#endif //OTHELLO_BOARDCHANGES_H
