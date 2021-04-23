#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define X 8
#define Y 8


struct boardSet{
    char board[X][Y];
};
struct boardMove{
    int row;
    int col;
    int player;
};
struct boardSet *setBoard();
struct boardMove *getmove(int turn);
int checkmove(struct boardSet *current,struct boardMove *move);
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
    new->player = turn;
    return(new);
}
int checkmove(struct boardSet *current,struct boardMove *move){
    int i,j;
    bool dirLeft = true;
    bool dirRight = true;
    bool dirUp = true;
    bool dirDown = true;
    bool diDiaU = true;
    bool dirDiaD = true;
    for(i=move->col;i<X;i++){
        if(current->board[move->row][i])
    }
}