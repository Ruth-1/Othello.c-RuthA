//
// Created by Ruth on 28/04/2021.
//

#ifndef OTHELLO_GLOBALVAR_H
#define OTHELLO_GLOBALVAR_H
#include <stdbool.h>
#define LEN 20
extern char p1[LEN];//holds player 1's name
extern char p2[LEN];//holds player 2's name
extern bool valid;//used for checking if a move is valid
extern bool passValid;//used for checking if a pass is valid
extern int player;//used to keep track of the players' turns
extern int freq[60];//used to check for two consecutive valid passes
extern int counter;//used to increment through freq array
extern int totalBlack;//used to count the total number of black discs
extern int totalWhite;//used to count the total number of white discs
#endif //OTHELLO_GLOBALVAR_H
