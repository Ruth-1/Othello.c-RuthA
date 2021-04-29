//
// Created by Ruth on 28/04/2021.
//
#include "voidFunc.h"
#include <stdio.h>//included for functions such as printf
#include <string.h>//used for string manipulations
#include "globalVar.h"//has global variable declarations
#define PLAYS 60//used as the max number of moves available
int totalWhite = 0;//set score for white to 0
int totalBlack = 0;//set score for black to 0
char p1[LEN];//declare p1 char to be of size LEN
char p2[LEN];//declare p2 char to be of size LEN
bool passValid = true;//set pass valid to be true until proven otherwise
void printBoard(struct boardSet *current){//prints out board
    printf("\n          Current Board:      \n");//used for formatting
    printf("____________________________________\n");//used for formatting
    int i,j;//used to iterate through 2D char array
    int row = 1;//used to write out row numbers
    printf("     a   b   c   d   e   f   g   h  \n");//used for column specifications
    printf("     _   _   _   _   _   _   _   _  \n");//used for formatting
    for(i=0;i<X;i++){//loops through rows
        printf("%d  |",row);//prints row number
        for(j=0;j<Y;j++){//loops through columns
            printf(" %c |", current->board[i][j]);//prints out columns
        }
        row++;//increment while we loop
        printf("\n     _   _   _   _   _   _   _   _  \n");//used for formatting
    }
}
void playerNames(){//processes player names
    int len;//used to get length of string
    printf("*** Welcome to Othello! ***\n");
    printf("Enter name of Player 1 (Black):\n");
    fgets(p1,LEN,stdin);//takes a string of max 20 characters from user
    len = strlen(p1);//get the length of the string
    if(p1[len-1] == '\n' )//strip newline from string entered
        p1[len-1] = 0;
    printf("Enter name of Player 2 (White):\n");
    fgets(p2,LEN,stdin);
    len = strlen(p2);
    if(p2[len-1] == '\n' )
        p2[len-1] = 0;
}

void freqInitialize(){//initializes freq array to all 0 to avoid errors
    for(int i=0;i<PLAYS;i++){
        freq[i] = 0;
    }
}


void countPieces(struct boardSet *current){//counts pieces
    totalBlack=0;//start at 0
    totalWhite=0;//start at 0
    for(int i = 0;i<X;i++){//iterates through rows
        for(int j=0;j<Y;j++){//iterates through columns
            if(current->board[i][j] == 'B'){
                totalBlack++;//if we see a black piece increment totalBlack
            }
            if(current->board[i][j] == 'W'){
                totalWhite++;//if we see a white piece increment totalWhite
            }
        }
    }
}
void checkPass(int row, int col,struct boardSet *current,char ply){//checks if a pass is valid
    int i,j,checkRow,checkCol,row2,col2;
    char otherPly;
    if(ply == 'B'){
        otherPly = 'W';//if current player is Black t set other Player to White and vice versa
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
