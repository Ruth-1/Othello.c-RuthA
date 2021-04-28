#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "boolFunc.h"
#include "voidFunc.h"
#include "globalVar.h"
#include <time.h>
#include "string.h"
#define LEN 20
#define X 8
#define Y 8
bool valid = false;
int freq[60];

int main() {
    FILE *fptr;
    freqInitialize(freq);
    playerNames();
    struct boardSet *current;
    struct boardSet *new;
    struct boardMove *move;
    current = setBoard();
    printBoard(current);
    while(boardFull(current) && doublePass(freq) && pieceExist(current)){
        do {
            valid = false;
            move = getMove(player,current);
            if(move->col == 'p' - 'a'&& move->row == -1){
                break;
            }
            new = checkMove(current, *move);
            free(move);
        } while (new == NULL);
        if(move->row != -1 && move->col != 'p' - 'a'){
            free(current);
            current = new;
            printBoard(current);
        }
    }
    countPieces(current);
    fptr= fopen("othello-results.txt","w");
    if(fptr == NULL){
        exit(1);
    }
    char str[] = "\nThe date and time of the game is:";
    time_t t;
    time(&t);
    fprintf(fptr,"%s", str);
    fprintf(fptr, "%s" ,strcat(ctime(&t),"\n"));

    if(totalWhite<totalBlack){
        printf("\nWell Done %s! You Won with a total of %d discs!!\n" ,p1,totalBlack);
        fprintf(fptr,"%s",strcat(p1,"won with a disc total of:"));
        fprintf(fptr, "%d" ,totalBlack);
    }
    if(totalWhite>totalBlack){
        printf("\nWell Done %s! You Won with a total of %d discs!!\n",p2,totalWhite);
        fprintf(fptr,"%s",strcat(p2,"won with a disc total of: "));
        fprintf(fptr, "%d" ,totalWhite);
    }
    if(totalWhite==totalBlack){
        printf("\nWell Done %s and %s! It was a draw!!\n",p1,p2);
        char str2[] = "It was a draw with both players having a disc total of: ";
        fprintf(fptr,"%s",str2);
        fprintf(fptr, "%d" ,totalBlack);
    }
    return 0;
}

