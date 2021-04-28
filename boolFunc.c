//
// Created by Ruth on 27/04/2021.
//

#include "boolFunc.h"
#include <stdbool.h>
#include "globalVar.h"
#include <stdio.h>
#define LEN 20
#define X 8
#define Y 8
bool passValid = true;
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
    if(pieceExist(current)) {
        char ply;
        if (playerp == 1) {
            ply = 'B';
        }
        if (playerp == 2) {
            ply = 'W';
        }
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (current->board[i][j] == ply) {
                    checkPass(i, j, current, ply);
                }
            }
        }
        if (passValid) {
            return true;
        }
        return false;
    }
    return true;
}

void checkPass(int row, int col,struct boardSet *current,char ply){
    int i,j,checkRow,checkCol,row2,col2;
    char otherPly;
    if(ply == 'B'){
        otherPly = 'W';
    }
    if(ply == 'W'){
        otherPly = 'B';
    }
    for(i=-1;i<=1;i++) {
        for (j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                // printf("\nCheck 6\n");
                checkRow = i;
                checkCol = j;
                // printf("\nCHECK DIRECTIONS Row:%d, Column:%d\n" ,move.row+i,move.col+j);

                row2 = row + checkRow;
                col2 = col + checkCol;
                if(checkBounds(row2,col2)){
                    if(current->board[row2][col2] == otherPly){
                //printf("\nOTHERS OPPS Row:%d, Column:%d\n" ,row,col);
                        while(current->board[row2][col2] == otherPly && checkBounds(row2,col2)){
                            row2 += checkRow;
                            col2 +=checkCol;
                    //   printf("\nCheck 1\n");
                    //  printf("\nOTHERS OPPS NESTED Row:%d, Column:%d\n" ,row,col);
                        }
                        if(current->board[row2][col2] == '*' && checkBounds(row2,col2) ){
                            passValid = false;
                            char colchar = col2 + 'a';
                            printf("\nInvalid Pass:Valid move at column:%c row:%d\n",colchar,row2+1);
                        }
                    }
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
    return true;
}