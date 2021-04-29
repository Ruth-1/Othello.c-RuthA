//
// Created by Ruth on 27/04/2021.
//

#include "boolFunc.h"
#include <stdbool.h>//used for booleans
#include "globalVar.h"//contains global variable declarations
#include "voidFunc.h"//contains function that return void
#define LEN 20
#define X 8
#define Y 8
#define PLAYS 60
bool checkBounds (int row, int col){//checks if the inputted row and column are in the bound of the board
    if(row <X && row >= 0 && col <Y && col >= 0){//the row and column both have to be less that 8 and greater than 0
        return true;
    }
    else{//if this is not the case then return false
        return false;
    }
}


bool doublePass(int arr[]){//checks if there have been two consecutive passes in the game
    for(int i=0;i<PLAYS -1;i++){
        if(freq[i] == 1 && freq[i+1] == 1){//the second it comes across two 1's in a row it returns false
            return false;
        }
    }//otherwise it returns true
    return true;
}


bool boardFull(struct boardSet *current){//checks if board is full
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == '*'){//iterates through board  and once it finds a blank space it returns true
                return true;
            }
        }
    }//otherwise it returns false
    return false;
}
bool validPass(int playerP,struct boardSet *current){//used to check if a pass is valid
    if(pieceExist(current)) {//it first checks if there is at least one disc of each player
        char ply;
        if (playerP == 1) {//if it's player 1's turn search for 'B'
            ply = 'B';
        }
        if (playerP == 2) {//if it's player 2's turn search for 'W'
            ply = 'W';
        }
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {//iterate through board and pass any positions that have the players disc
                // into the checkPass function
                if (current->board[i][j] == ply) {
                    checkPass(i, j, current, ply);
                }
            }
        }
        if (passValid) {//if after checking all the players discs we don't find any valid moves then return true;the
            // pass is valid
            return true;
        }
        //else return false;the pass is not valid
        return false;
    }
    return true;//if there is not at least one disc of each player return true;the pass is valid
}


bool pieceExist(struct boardSet *current){//checks if there is at least one disc of each player on the board
    int checkB = 0;//set checks to 0 at first
    int checkW = 0;
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){//iterate through board
            if(current->board[i][j] == 'W'){
                checkW++;//if we encounter a white disc increment its check
            }
            if(current->board[i][j] == 'B'){
                checkB++;//if we encounter a black disc increment its check
            }
        }
    }
    if(checkB == 0 || checkW == 0) {//if either check is still 0 return false;the piece does not exist
        return false;
    }
    //otherwise return true;the piece does exist
    return true;
}