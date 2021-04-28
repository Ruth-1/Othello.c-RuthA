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

void freqInitialize(int arr[]){
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