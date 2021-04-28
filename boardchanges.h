//
// Created by Ruth on 27/04/2021.
//

#ifndef OTHELLO_BOARDCHANGES_H
#define OTHELLO_BOARDCHANGES_H
#define X 8
#define Y 8
struct boardSet{
    char board[X][Y];
};

struct boardMove{
    int row;
    int col;
    char player;
};
struct boardSet *setBoard();
struct boardMove *getMove(int turn,struct boardSet *current);
struct boardSet *checkMove (struct boardSet *current,struct boardMove move);
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection);


#endif //OTHELLO_BOARDCHANGES_H
