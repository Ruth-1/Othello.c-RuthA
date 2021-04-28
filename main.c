#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "boolFunc.h"
#include "boardchanges.h"
#include "voidFunc.h"
#include "globalVar.h"
#define LEN 20
#define X 8
#define Y 8
bool valid = false;
int freq[60];

/*struct boardSet{
    char board[X][Y];
};

struct boardMove{
    int row;
    int col;
    char player;
};
void freqInitialize(int arr[]);
bool doublePass(int arr[]);
bool boardFull(struct boardSet *current);
void countPieces(struct boardSet *current);
struct boardSet *setBoard();
struct boardMove *getmove(int turn);
struct boardSet *checkmove (struct boardSet *current,struct boardMove move);
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection);
bool checkBounds (int row, int col);
void printBoard(struct boardSet *current);
void playerNames();*/

int main() {
    freqInitialize(freq);
    playerNames();
    struct boardSet *current;
    struct boardSet *new;
    struct boardMove *move;
    current = setBoard();
    printBoard(current);
    while(boardFull(current) && doublePass(freq)){
        do {
            valid = false;
            move = getmove(player,current);
            if(move->col == 'p' - 'a'&& move->row == -1){
                break;
            }
            new = checkmove(current, *move);
            free(move);
        } while (new == NULL);
        if(move->row != -1 && move->col != 'p' - 'a'){
            free(current);
            current = new;
            printBoard(current);
        }
    }
    countPieces(current);
    if(totalWhite<totalBlack){
        printf("\nWell Done %s! You Won with a total of %d discs!!\n" ,p1,totalBlack);
    }
    if(totalWhite>totalBlack){
        printf("\nWell Done %s! You Won with a total of %d discs!!\n",p2,totalWhite);
    }
    if(totalWhite==totalBlack){
        printf("\nWell Done %s and %s! It was a draw!!\n",p1,p2);
    }

    return 0;
}

