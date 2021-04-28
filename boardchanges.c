//
// Created by Ruth on 27/04/2021.
//
#include <stdio.h>
#include "boardchanges.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "boolFunc.h"
#include "globalVar.h"
#define LEN 20
#define X 8
#define Y 8
int player = 1;
int counter = 0;
struct boardSet *setBoard(){
    int i,j;
    struct boardSet *new;
    new = malloc(sizeof(struct boardSet));
    for(i = 0;i<X;i++){
        for(j=0;j<Y;j++){
            new->board[i][j]= '*';
        }
    }
    new->board[3][3] = 'W';
    new->board[3][4] = 'B';
    new->board[4][3] = 'B';
    new->board[4][4] = 'W';
    return new;
}

struct boardMove *getmove(int turn,struct boardSet *current){
    struct boardMove *move;
    char col;
    char rowtemp;
    char buffer;
    int row;
    char pName[LEN];
    move = malloc(sizeof(struct boardMove));
    //printf("\nTURN IS: %d\n" ,turn);
    if(turn == 1){
        move->player = 'B';
        strcpy(pName,p1);
    }
    else if(turn == 2){
        move->player = 'W';
        strcpy(pName,p2);
    }
    do {
        passValid = true;
        printf("%s,%s", pName, "enter your move in the format a-h for your "
                               "desired column and 1-8 for your desired row\n");
        printf("If you wish to pass please enter p and enter.\n");
        scanf("%1c", &col);
        move->col = col - 'a';
        scanf("%1c", &rowtemp);
        if(col == 'p'&& rowtemp == '\n'){
            row = 0;
        }
        if(rowtemp != '\n'){
            row = (rowtemp - '0');
            scanf("%c" ,&buffer);
        }
        move->row = row - 1;
    }while(!(checkBounds(row - 1,col - 'a')) && !((col == 'p' && row == 0) && (validPass(turn,current))));
    if((col == 'p' && row == 0) && passValid){
        if(turn == 1){
            player = 2;
        }
        else if(turn == 2){
            player = 1;
        }
    }
    if((col == 'p' && row == 0) && passValid){
        freq[counter] = 1;
        counter++;
    }

    // printf("\n Function running well.\n");
    //  printf(" FROM GET MOVE :%d:row; %d:column.\n" ,move->row, move->col);
    return move;
}
struct boardSet *checkmove(struct boardSet *current,struct boardMove move) {
    int i, j;
    struct boardSet *new;
    struct boardMove checkDirection = {0,0,0};

    if(current->board[move.row][move.col] != '*') {
        // printf("\nCheck 7\n");
        return NULL;
    }
    new = setBoard();
    *new = *current;
    for(i=-1;i<=1;i++) {
        for (j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                // printf("\nCheck 6\n");
                checkDirection.row = i;
                checkDirection.col = j;
                new = turnPiece(new, move, &checkDirection);
                // printf("\nCHECK DIRECTIONS Row:%d, Column:%d\n" ,move.row+i,move.col+j);
            }
        }
    }
    if(valid){
        new->board[move.row][move.col] = move.player;
        // printf("\nFunction running well!\n");
        if(move.player == 'B'){
            player = 2;
        }
        else if(move.player == 'W'){
            player = 1;
        }
        freq[counter] = 0;
        counter++;
        return new;

    }
    else {
        free(new);
        // printf("\nCheck 4\n");
        return NULL;
    }
}
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection){
    int row, col;
    char ply;
    if (move.player == 'B') {
        ply = 'W';
    }
    if(move.player == 'W'){
        ply = 'B';
    }
    row = move.row + checkDirection->row;
    col = move.col + checkDirection->col;
    if(checkBounds(row,col)){
        if(new->board[row][col] == ply){
            //printf("\nOTHERS OPPS Row:%d, Column:%d\n" ,row,col);
            while(new->board[row][col] == ply && checkBounds(row,col)){
                row += checkDirection->row;
                col +=checkDirection->col;
                //   printf("\nCheck 1\n");
                //  printf("\nOTHERS OPPS NESTED Row:%d, Column:%d\n" ,row,col);
            }
            if(new->board[row][col] == move.player && checkBounds(row,col) ){
                row = move.row + checkDirection->row;
                col = move.col + checkDirection->col;
                while(new->board[row][col] == ply && checkBounds(row,col)){
                    new->board[row][col] = move.player;
                    row += checkDirection->row;
                    col +=checkDirection->col;
                    valid = true;
                    //   printf("\nCheck 2\n");
                }
            }
        }
    }
    return new;
}