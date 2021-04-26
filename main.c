#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define X 8
#define Y 8
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
void printBoard(struct boardSet *current);
void playerNames();
int main() {
    playerNames();
    struct boardSet *current;
    setBoard();
    current = setBoard();
    printBoard(current);
    int try = 'b' - 'a';
    printf("\nTry is %d\n" ,try);
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
    char p1[20];
    char p2[20];
    printf("*** Welcome to Othello! ***\n");
    printf("Enter name of Player 1 (Black):\n");
    fgets(p1,20,stdin);
    printf("Enter name of Player 2 (White):\n");
    fgets(p2,20,stdin);
}
struct boardMove *getmove(int turn){
    struct boardMove *new;
    char col;
    int row;
    new = malloc(sizeof(struct boardMove));
    printf("%s","Player enter your move in the format 1-8 for your "
                "desired row and a-h for your desired column\n");
    scanf("%d" ,&row);
    new->row = row -1;
    scanf("%c" ,&col);
    new->col = col - 'a';
    if(turn == 1){
        new->player = 'B';
    }
    else if(turn == 2){
        new->player = 'W';
    }

    return(new);
}
struct boardSet *checkmove(struct boardSet *current,struct boardMove move) {
    int i, j;
    char ply;
    struct boardSet *new;
    new = malloc(sizeof(struct boardSet));
    struct boardMove checkDirection;

    if (move.player == 'B') {
        ply = 'W';
    } else {
        ply = 'B';
    }
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
    if(row <X && row <= 0 && col <Y && col <= 0){
        if(new->board[row][col] == ply){
            while(new->board[row][col] == ply && row <X && row <= 0 && col <Y && col <= 0){
                row += checkDirection->row;
                col +=checkDirection->col;
            }
            if(new->board[row][col] == move.player && row <X && row <= 0 && col <Y && col <= 0 ){
                row = move.row + checkDirection->row;
                col = move.col + checkDirection->col;
                valid = true;
                while(new->board[row][col] == ply && row <X && row <= 0 && col <Y && col <= 0){
                    new->board[row][col] = move.player;
                    row += checkDirection->row;
                    col +=checkDirection->col;
                }
            }
        }
    }
    return new;
}