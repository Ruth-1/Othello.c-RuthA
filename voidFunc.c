//
// Created by Ruth on 28/04/2021.
//
#include "voidFunc.h"
#include <stdio.h>
#include <string.h>
#include "globalVar.h"
int totalWhite = 0;
int totalBlack = 0;
char p1[LEN];
char p2[LEN];
bool passValid = true;
void printBoard(struct boardSet *current){
    printf("\n          Current Board:      \n");
    printf("____________________________________\n");
    int i,j;
    int row = 1;
    printf("     a   b   c   d   e   f   g   h  \n");
    printf("     _   _   _   _   _   _   _   _  \n");
    for(i=0;i<X;i++){
        printf("%d  |",row);
        for(j=0;j<Y;j++){
            printf(" %c |", current->board[i][j]);
        }
        row++;
        printf("\n     _   _   _   _   _   _   _   _  \n");
    }
}
void playerNames(){
    int len;
    printf("*** Welcome to Othello! ***\n");
    printf("Enter name of Player 1 (Black):\n");
    fgets(p1,LEN,stdin);
    len = strlen(p1);
    if(p1[len-1] == '\n' )
        p1[len-1] = 0;
    printf("Enter name of Player 2 (White):\n");
    fgets(p2,LEN,stdin);
    len = strlen(p2);
    if(p2[len-1] == '\n' )
        p2[len-1] = 0;
}

void freqInitialize(){
    for(int i=0;i<60;i++){
        freq[i] = 0;
    }
}


void countPieces(struct boardSet *current){
    totalBlack=0;
    totalWhite=0;
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == 'B'){
                totalBlack++;
            }
            if(current->board[i][j] == 'W'){
                totalWhite++;
            }
        }
    }
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
                checkRow = i;
                checkCol = j;
                row2 = row + checkRow;
                col2 = col + checkCol;
                if(checkBounds(row2,col2)){
                    if(current->board[row2][col2] == otherPly){
                        while(current->board[row2][col2] == otherPly && checkBounds(row2,col2)){
                            row2 += checkRow;
                            col2 +=checkCol;
                        }
                        if(current->board[row2][col2] == '*' && checkBounds(row2,col2) ){
                            passValid = false;
                            char colChar = col2 + 'a';
                            printf("\nInvalid Pass:Valid move at column:%c row:%d\n",colChar,row2+1);
                        }
                    }
                }
            }
        }
    }
}
