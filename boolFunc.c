//
// Created by Ruth on 27/04/2021.
//

#include "boolFunc.h"
#include <stdbool.h>
#include "globalVar.h"
#include <stdio.h>
#include "voidFunc.h"
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