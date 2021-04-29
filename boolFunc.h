//
// Created by Ruth on 27/04/2021.
//

#ifndef OTHELLO_BOOLFUNC_H
#define OTHELLO_BOOLFUNC_H
#include "boardchanges.h"
#include <stdbool.h>
bool doublePass(int arr[]);//checks if there have been two consecutive passes in the game
bool boardFull(struct boardSet *current);//checks if board is full
bool checkBounds (int row, int col);//checks if the inputted row and column are in the bound of the board
bool validPass(int playerP,struct boardSet *current);//used to check if a pass is valid
bool pieceExist(struct boardSet *current);//checks if there is at least one disc of each player on the board
#endif //OTHELLO_BOOLFUNC_H
