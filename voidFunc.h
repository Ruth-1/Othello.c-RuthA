//
// Created by Ruth on 28/04/2021.
//

#ifndef OTHELLO_VOIDFUNC_H
#define OTHELLO_VOIDFUNC_H
#include "boardchanges.h"
#include "boolFunc.h"
void printBoard(struct boardSet *current);//prints out board
void playerNames();//processes player names
void freqInitialize();//initializes freq array to all 0 to avoid errors
void countPieces(struct boardSet *current);//counts discs
void checkPass(int row, int col,struct boardSet *current,char ply);//checks if a pass is valid
#endif //OTHELLO_VOIDFUNC_H
