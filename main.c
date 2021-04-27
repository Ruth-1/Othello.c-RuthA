#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LEN 20
#define X 8
#define Y 8
char p1[LEN];
char p2[LEN];
bool valid = false;
int player = 1;
int freq[60];
int counter = 0;
int totalBlack;
int totalWhite;

struct boardSet{
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
void playerNames();
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
            move = getmove(player);
            if(move->row == -1 && move->col == '0' - 'a'){
                break;
            }
            new = checkmove(current, *move);
            free(move);
        } while (new == NULL);
        free(current);
        current = new;
        printBoard(current);
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
    int len;
    printf("*** Welcome to Othello! ***\n");
    printf("Enter name of Player 1 (Black):\n");
    fgets(p1,LEN,stdin);
    len = strlen(p1);
    if(p1[len-1] == '\n' )
        p1[len-1] = 0;
    printf("Enter name of Player 2 (White):\n");
    fgets(p2,LEN,stdin);
    len = strlen(p2);
    if(p2[len-1] == '\n' )
        p2[len-1] = 0;
}
struct boardMove *getmove(int turn){
    struct boardMove *move;
    char col;
    int row;
    char pName[LEN];
    move = malloc(sizeof(struct boardMove));
    printf("\nTURN IS: %d\n" ,turn);
    if(turn == 1){
        move->player = 'B';
        strcpy(pName,p1);
    }
    else if(turn == 2){
        move->player = 'W';
        strcpy(pName,p2);
    }
    do {
        printf("%s,%s", pName, "enter your move in the format 1-8 for your "
                               "desired row and a-h for your desired column\n");
        printf("If you wish to pass please enter 0 for your desired row and column.\n");
        scanf("%d", &row);
        move->row = row - 1;
        scanf(" %c", &col);
        move->col = col - 'a';
    }while(!(checkBounds(row - 1,col - 'a')) && !(row  == 0 && col == '0' ));
    if(row  == 0 && col == '0' ){
        if(turn == 1){
            player = 2;
        }
        else if(turn == 2){
            player = 1;
        }
    }
    if(move->row == -1 && move->col == '0' - 'a'){
        freq[counter] = 1;
        counter++;
    }

    printf("\n Function running well.\n");
    printf(" FROM GET MOVE :%d:row; %d:column.\n" ,move->row, move->col);
    return move;
}
struct boardSet *checkmove(struct boardSet *current,struct boardMove move) {
    int i, j;
    struct boardSet *new;
    struct boardMove checkDirection = {0,0,0};

    if(current->board[move.row][move.col] != '*') {
        printf("\nCheck 7\n");
        return NULL;
    }
    new = setBoard();
    *new = *current;
    for(i=-1;i<=1;i++) {
        for (j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                printf("\nCheck 6\n");
                checkDirection.row = i;
                checkDirection.col = j;
                new = turnPiece(new, move, &checkDirection);
                printf("\nCHECK DIRECTIONS Row:%d, Column:%d\n" ,move.row+i,move.col+j);
            }
        }
    }
    if(valid){
        new->board[move.row][move.col] = move.player;
        printf("\nFunction running well!\n");
        if(move.player == 'B'){
            player = 2;
        }
        else if(move.player == 'W'){
            player = 1;
        }
        freq[counter] = 0;
        counter++;
        return new;

    }
    else {
        free(new);
        printf("\nCheck 4\n");
        return NULL;
    }
}
struct boardSet *turnPiece(struct boardSet *new,struct boardMove move,struct boardMove *checkDirection){
    int row, col;
    char ply;
    if (move.player == 'B') {
        ply = 'W';
    }
    if(move.player == 'W'){
        ply = 'B';
    }
    row = move.row + checkDirection->row;
    col = move.col + checkDirection->col;
    if(checkBounds(row,col)){
        if(new->board[row][col] == ply){
            printf("\nOTHERS OPPS Row:%d, Column:%d\n" ,row,col);
            while(new->board[row][col] == ply && checkBounds(row,col)){
                row += checkDirection->row;
                col +=checkDirection->col;
                printf("\nCheck 1\n");
                printf("\nOTHERS OPPS NESTED Row:%d, Column:%d\n" ,row,col);
            }
            if(new->board[row][col] == move.player && checkBounds(row,col) ){
                row = move.row + checkDirection->row;
                col = move.col + checkDirection->col;
                while(new->board[row][col] == ply && checkBounds(row,col)){
                    new->board[row][col] = move.player;
                    row += checkDirection->row;
                    col +=checkDirection->col;
                    valid = true;
                    printf("\nCheck 2\n");
                }
            }
        }
    }
    return new;
}
bool checkBounds (int row, int col){
    if(row <X && row >= 0 && col <Y && col >= 0){
        printf("\nCheck 3\n");
        return true;
    }
    else{
        return false;
    }
}

void freqInitialize(int arr[]){
    for(int i=0;i<60;i++){
        freq[i] = 0;
    }
}

bool doublePass(int arr[]){
    for(int i=0;i<60 -1;i++){
        if(freq[i] == 1 && freq[i+1] == 1){
            return false;
        }
    }
    return true;
}


bool boardFull(struct boardSet *current){
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == '*'){
                return true;
            }
        }
    }
    return false;
}
void countPieces(struct boardSet *current){
    totalBlack=0;
    totalWhite=0;
    for(int i = 0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(current->board[i][j] == 'B'){
                totalBlack++;
            }
            if(current->board[i][j] == 'W'){
                totalWhite++;
            }
        }
    }
}