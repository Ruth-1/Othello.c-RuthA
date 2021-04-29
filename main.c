#include <stdio.h>//used for functions such as printf
#include <stdlib.h> //used for dynamic memory allocation
#include <stdbool.h>//used for booleans
#include "boolFunc.h"//contains bool functions
#include "voidFunc.h"//contains all void functions
#include "globalVar.h"//contains global variable declarations
#include <time.h>//used to print out date and time to file
#include "string.h"//used for string manipulations
#define LEN 20//used for player names
#define X 8//used as dimensions for the board
#define Y 8//used as dimensions for the board
#define PLAYS 60
bool valid = false;//used to check if a move is valid
int freq[PLAYS];//used to check for two consecutive 1's in array(two valid passes ina row)

int main() {
    FILE *fptr;//used to point to file
    freqInitialize(freq);//initializes freq array with 0
    playerNames();//function that takes player names and assigns each player a colour
    struct boardSet *current;//board struct pointer
    struct boardSet *new;//board struct pointer
    struct boardMove *move;//board move pointer
    current = setBoard();//setBoard returns the initialized board array
    printBoard(current);//printBoard prints out boardSet structs
    while(boardFull(current) && doublePass(freq) && pieceExist(current)){//loop until end of game requirements are met
        do {
            valid = false; //set valid back to false every time we get a new move
            move = getMove(player,current);//getMove returns a boardMove struct containing the array index of players
            // move and player info
            if(move->col == 'p' - 'a'&& move->row == -1){//if the player passed and the pass is valid break out of
                // loop and move onto next player
                break;
            }
            new = checkMove(current, *move);//else if move is valid and not a pass checkMove returns a new board
            // after players move has been processed
            free(move);//free the memory
        } while (new == NULL);//loop while the move entered is invalid
        if(move->row != -1 && move->col != 'p' - 'a'){//if the move entered was not a pass
            free(current);//free the memory at pass
            current = new;//assign current the updated board
            printBoard(current);//print the board
        }
        countPieces(current);//after each move count the pieces of each player and print them to screen
        printf("\n%s has a a total of %d discs.\n",p1,totalBlack);
        printf("\n%s has a a total of %d discs.\n",p2,totalWhite);
    }
    countPieces(current);//at the end of the game count the pieces again
    fptr= fopen("othello-results.txt","w");//open txt file to write to
    if(fptr == NULL){
        exit(1);//if the file can't be opened, exit
    }
    char str[] = "\nThe date and time of the game is:";
    time_t t;//used to get time
    time(&t);//used to get time
    fprintf(fptr,"%s", str);//print str to file
    fprintf(fptr, "%s" ,strcat(ctime(&t),"\n"));//print time to file

    if(totalWhite<totalBlack){//if black has more discs black wins
        printf("\nWell Done %s! You Won with a total of %d discs!!\n" ,p1,totalBlack);//print out winner and score to
        // screen
        fprintf(fptr,"%s",strcat(p1," won with a disc total of:"));//print winner to file
        fprintf(fptr, "%d" ,totalBlack);//print total number of winners discs to file
    }
    if(totalWhite>totalBlack){//if white has more discs black wins
        printf("\nWell Done %s! You Won with a total of %d discs!!\n",p2,totalWhite);//print out winner and score to
        // screen
        fprintf(fptr,"%s",strcat(p2," won with a disc total of: "));//print winner to file
        fprintf(fptr, "%d" ,totalWhite);//print total number of winners discs to file
    }
    if(totalWhite==totalBlack){//if equal number of discs for each player then game ends in draw
        printf("\nWell Done %s and %s! It was a draw!! Both players got %d!\n",p1,p2,totalWhite);//print out results and score
        char str2[] = "It was a draw with both players having a disc total of: ";
        fprintf(fptr,"%s",str2);//print result and score to file
        fprintf(fptr, "%d" ,totalBlack);
    }
    return 0;
}

