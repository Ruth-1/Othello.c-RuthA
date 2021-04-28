//
// Created by Ruth on 27/04/2021.
//

#include "boolFunc.h"
#include <stdbool.h>
#include "globalVar.h"
#define LEN 20
#define X 8
#define Y 8

bool checkBounds (int row, int col){
    if(row <X && row >= 0 && col <Y && col >= 0){
        //  printf("\nCheck 3\n");
        return true;
    }
    else{
        return false;
    }
}


bool doublePass(int arr[]){
    for(int i=0;i<60 -1;i++){
        if(freq[i] == 1 && freq[i+1] == 1){
            return false;
        }
    }
    return true;
}


bool boardFull(struct boardSet *current){
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == '*'){
                return true;
            }
        }
    }
    return false;
}
bool validPass(int playerp,struct boardSet *current){
    int row, col;
    char ply;
    if (playerp == 1) {
        ply = 'B';
    }
    if(playerp == 2){
        ply = 'W';
    }
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == ply){
               checkPass(i,j,current);
            }
        }
    }

}
bool checkPass(int row, int col,struct boardSet *current){
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

}
bool pieceExist(struct boardSet *current){
    int checkB = 0;
    int checkW = 0;
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == 'W'){
                checkW++;
            }
            if(current->board[i][j] == 'B'){
                checkB++;
            }
        }
    }
    if(checkB == 0 || checkW == 0) {
        return false;
    }
    return true;-
}