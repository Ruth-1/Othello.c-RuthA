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