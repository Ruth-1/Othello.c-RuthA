//
// Created by Ruth on 28/04/2021.
//

#ifndef OTHELLO_VOIDFUNC_H
#define OTHELLO_VOIDFUNC_H
#include "boardchanges.h"
#include "boolFunc.h"
void printBoard(struct boardSet *current);
void playerNames();
void freqInitialize(int arr[]);
void countPieces(struct boardSet *current);
void checkPass(int row, int col,struct boardSet *current,char ply);
#endif //OTHELLO_VOIDFUNC_H
