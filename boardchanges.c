//
// Created by Ruth on 27/04/2021.
//
#include <stdio.h>//used for scanf and printf
#include "boardchanges.h"
#include <stdlib.h>//used for dynamically allocating memory
#include <stdbool.h>//used for booleans
#include <string.h>//used for string manipulation
#include "boolFunc.h"//contains bool functions
#include "globalVar.h"//contains global variable declarations
#define LEN 20
#define X 8
#define Y 8
int player = 1;//games starts with player one
int counter = 0;//counter for freq array
struct boardSet *setBoard(){//initializes the board
    int i,j;
    struct boardSet *new;//makes a pointer to boardSet struct
    new = malloc(sizeof(struct boardSet));//dynamically allocates memory to pointer
    for(i = 0;i<X;i++){
        for(j=0;j<Y;j++){//set all spaces as blank
            new->board[i][j]= '*';
        }
    }
    new->board[3][3] = 'W';//fill in mandatory spaces as required
    new->board[3][4] = 'B';
    new->board[4][3] = 'B';
    new->board[4][4] = 'W';
    return new;//return the pointer
}

struct boardMove *getMove(int turn,struct boardSet *current){//gets move from player
    struct boardMove *move;//pointer to boardMove struct
    char col;
    char rowTemp;
    char buffer;//used to clear out scanf
    int row;
    char pName[LEN];
    move = malloc(sizeof(struct boardMove));//dynamically allocate memory to pointer
    if(turn == 1){//if player 1 call player 1's name and vice versa
        move->player = 'B';
        strcpy(pName,p1);
    }
    else if(turn == 2){
        move->player = 'W';
        strcpy(pName,p2);
    }
    do {
        passValid = true;//set pass as valid until proven otherwise
        printf("\n%s,%s", pName, "enter your move in the format a-h for your "
                               "desired column and 1-8 for your desired row\n");
        printf("If you wish to pass please enter p and enter.\n");
        scanf("%1c", &col);//takes column
        move->col = col - 'a';//translate to corresponding array index notation
        scanf("%1c", &rowTemp);//take in row
        if(col == 'p'&& rowTemp == '\n'){//if player enters pass set row to 0
            row = 0;
        }
        if(rowTemp != '\n'){//if a pass has not been entered use a buffer to accept the enter character
            row = (rowTemp - '0');//set row to corresponding int value
            scanf("%c" ,&buffer);
        }
        move->row = row - 1;//set row to corresponding index notation
        if(!checkBounds(row - 1,col - 'a') && !(col == 'p' && row == 0)){//if the user enters an invalid move (not
            // including passes)
            printf("\nInvalid Move.\n");
        }
    }while(!(checkBounds(row - 1,col - 'a')) && !((col == 'p' && row == 0) && (validPass(turn,current))));
    // loop while user continues to enter an invalid move or pass

    if((col == 'p' && row == 0) && passValid){//if a valid pass is entered then move to other player
        if(turn == 1){
            player = 2;
        }
        else if(turn == 2){
            player = 1;
        }
    }
    if((col == 'p' && row == 0) && passValid){//if a valid pass entered then set frq array index to 1
        freq[counter] = 1;
        counter++;
    }

    return move;//return move pointer
}
struct boardSet *checkMove(struct boardSet *current,struct boardMove move) {//function that checks if move is valid
    int i, j;
    struct boardSet *new;//pointer to struct boardSet
    struct boardMove checkDirection = {0,0,0};//initialize boardMove struct checkDirection

    if(current->board[move.row][move.col] != '*') {//if position entered is already occupied
        printf("\nInvalid Move.\n");
        return NULL;
    }
    new = setBoard();//initializes pointer
    *new = *current;//assign the current board to the new board
    for(i=-1;i<=1;i++) {//controls row manipulations
        for (j = -1; j <= 1; j++) {//controls column manipulations
            if (i != 0 || j != 0) {//enter only at least either row manipulator or column manipulator isn't 0
                checkDirection.row = i;
                checkDirection.col = j;
                new = turnPiece(new, move, &checkDirection);//new board is made from turnPiece function
            }
        }
    }
    if(valid){//if valid has not been changed to false in the turnPiece function
        new->board[move.row][move.col] = move.player;//place users piece on the board
        if(move.player == 'B'){//move to other player
            player = 2;
        }
        else if(move.player == 'W'){
            player = 1;
        }
        freq[counter] = 0;//set freq index for this move to 0
        counter++;
        return new;//return the new board

    }
    else {//if valid is false
        printf("\nInvalid Move.\n");
        free(new);
        return NULL;
    }
}
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection){//checks if a
    // move is valid and if it is,flips the corresponding discs
    int row, col;
    char ply;
    if (move.player == 'B') {//set ply to opponent's colour
        ply = 'W';
    }
    if(move.player == 'W'){
        ply = 'B';
    }
    row = move.row + checkDirection->row;//manipulated row
    col = move.col + checkDirection->col;//manipulated column
    if(checkBounds(row,col)){//if the manipulated position is in the board bounds
        if(new->board[row][col] == ply){//if the manipulated position has opponent's disc
            while(new->board[row][col] == ply && checkBounds(row,col)){//continue in that direction until we exit
                // the board bounds or until we land on a position that doesn't have the opponent's disc
                row += checkDirection->row;
                col +=checkDirection->col;
            }
            if(new->board[row][col] == move.player && checkBounds(row,col) ){//if we are still in boards bounds and
                // we reach a piece of the current player
                //go back to the first manipulated position and continue in that direction 'flipping' the
                // opponent's disc to the current player's colour
                row = move.row + checkDirection->row;
                col = move.col + checkDirection->col;
                while(new->board[row][col] == ply && checkBounds(row,col)){
                    new->board[row][col] = move.player;
                    row += checkDirection->row;
                    col +=checkDirection->col;
                    valid = true;//set valid to true
                }
            }
        }
    }
    return new;//return pointer to updated board struct
}