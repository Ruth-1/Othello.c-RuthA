#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define X 8
#define Y 8
char p1[20];
char p2[20];
bool valid = false;

struct boardSet{
    char board[X][Y];
};
struct boardMove{
    int row;
    int col;
    char player;
};
struct boardSet *setBoard();
struct boardMove *getmove(int turn);
struct boardSet *checkmove (struct boardSet *current,struct boardMove move);
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection);
bool checkBounds (int row, int col);
void printBoard(struct boardSet *current);
void playerNames();
int main() {
    int turn = 1;
    playerNames();
    struct boardSet *current;
    struct boardMove *move;
    setBoard();
    current = setBoard();
    printBoard(current);
    move = getmove(turn);
    checkmove(current, *move);
    printBoard(current);

    return 0;
}
struct boardSet *setBoard(){
    int i,j;
    struct boardSet *new;
    new = malloc(sizeof(struct boardSet));
    for(i = 0;i<X;i++){
        for(j=0;j<Y;j++){
            new->board[i][j]= '*';
        }
    }
    new->board[3][3] = 'W';
    new->board[3][4] = 'B';
    new->board[4][3] = 'B';
    new->board[4][4] = 'W';
    return new;
}
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
    printf("*** Welcome to Othello! ***\n");
    printf("Enter name of Player 1 (Black):\n");
    fgets(p1,20,stdin);
    printf("Enter name of Player 2 (White):\n");
    fgets(p2,20,stdin);
}
struct boardMove *getmove(int turn){
    struct boardMove *move;
    char col;
    int row;
    char pName[20];
    move = malloc(sizeof(struct boardMove));
    if(turn == 1){
        move->player = 'B';
        strcpy(pName,p1);
    }
    else if(turn == 2){
        move->player = 'W';
        strcpy(pName,p2);
    }
    printf("%s,%s", p1, "enter your move in the format 1-8 for your "
                "desired row and a-h for your desired column\n");
    scanf("%d" ,&row);
    move->row = row - 1;
    scanf(" %c" ,&col);
    move->col = col - 'a';
    printf("\n Function running well.\n");
    printf("%d:row; %d:column.\n" ,move->row, move->col);
    return move;
}
struct boardSet *checkmove(struct boardSet *current,struct boardMove move) {
    int i, j;
    struct boardSet *new;
    struct boardMove checkDirection = {0,0,0};

    if(current->board[move.row][move.col] != '*') {
        return NULL;
    }
    new = setBoard();
    *new = *current;
    for(i=-1;i<=1;i++) {
        for (j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                checkDirection.row = i;
                checkDirection.col = j;
                new = turnPiece(new, move, &checkDirection);
            }
        }
    }
    if(valid){
        new->board[move.row][move.col] = move.player;
        printBoard(new);
        return new;
    }
    else {
        free(new);
        return NULL;
    }
}
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection){
    int row, col;
    char ply;
    if (move.player == 'B') {
        ply = 'W';
    } else if(move.player){
        ply = 'B';
    }
    row = move.row + checkDirection->row;
    col = move.col + checkDirection->col;
    if(checkBounds(row,col)){
        if(new->board[row][col] == ply){
            while(new->board[row][col] == ply && checkBounds(row,col)){
                row += checkDirection->row;
                col +=checkDirection->col;
            }
            if(new->board[row][col] == move.player && checkBounds(row,col) ){
                row = move.row + checkDirection->row;
                col = move.col + checkDirection->col;
                valid = true;
                while(new->board[row][col] == ply && checkBounds(row,col)){
                    new->board[row][col] = move.player;
                    row += checkDirection->row;
                    col +=checkDirection->col;
                }
            }
        }
    }
    return new;
}
bool checkBounds (int row, int col){
    if(row <X && row >= 0 && col <Y && col >= 0){
        return true;
    }
    else{
        return false;
    }
}