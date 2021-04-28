//
// Created by Ruth on 27/04/2021.
//

#ifndef OTHELLO_BOOLFUNC_H
#define OTHELLO_BOOLFUNC_H
#include "boardchanges.h"
#include <stdbool.h>
bool doublePass(int arr[]);
bool boardFull(struct boardSet *current);
bool checkBounds (int row, int col);
bool validPass(int playerp,struct boardSet *current);
bool pieceExist(struct boardSet *current);
bool checkPass(int row, int col,struct boardSet *current);
#endif //OTHELLO_BOOLFUNC_H
