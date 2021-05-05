# Othello.c-RuthA
Othello game implemented in
The Thought Process Behind my Code

Implementation of the Board
I decided to use a struct that contained a 2D char array to hold the information for each board space
I used the character '*' to symbolise a blank space on the board - ie one not occupied by a white/black disks
I first initialised my board struct to be be all 'blank spaces' except for the four mandatory spaces that had to be
filled with two white and two black pieces.

Implementation of the Players
When asking the users to input their names I automatically assigned the first player to be black and the second player
to be white. I take the user names and store them in global char array variables so I can use their names in multiple
functions.

Implementation of the discs
I implemented the discs by using the character 'B' and 'W' to represent a black disc and white disc respectively.
If a move is seen as valid I would then change the '*' symbol to whatever character (either 'B' or 'W') that the move
dictates.

Implementation of a move
I used another struct to store the move inputted by the player and to store the current player information.
I took in the users move in the format a1 where a can be between a-h (to represent the columns) and 1 can be between 1-8
(to represent the rows)
I then stored these characters in temporary variables and then translated them to their correct array index notation.


Game Logic
The game started off with player 1 (black) going first.
To check if it was valid I first checked if the move was entered in the correct format, if it was in the bounds of the
board and if that position was not already occupied.

To check if it was a valid move for the player I took the position inputted by the player as the centerpiece and checked
all 8 directions bordering that piece to see if it would capture one (or more) white pieces.
To do this I used a function that manipulated the move entered using array indexing.

I first decrement the row and column of the inputted move (ex. Move entered: Row:4,Column:c. Decremented move: Row:3,
Column:b ie going in an upwards diagonal to the left).
If there is a white piece in that position, I continue to decrement my row and column until I reach a back piece or  I
reach the edge corner/position on the board. If I don’t find a white piece  in the decremented move or if  I reach the
edge of the board without finding another black piece, I change the manipulation of the inputted move.
I keep the row decremented but I leave the column inputted by the player. (ex Manipulated Position: Row:3,Column c ie
going in a straight upwards line from the inputted move).
I then do the same process. I continue to manipulate my row and column in this way until I find a valid move or until I
have checked all 8 directions with no valid move found.

For example in the first move inputted by black(ex:Row:4, Column:c), when I manipulate the move by keeping the row
entered by the player but incrementing the column(Manipulated Position: Row:4 Column: d ie going right from the inputted
move) I land on a white piece. I continue manipulating the position in the same fashion and then I reach a black piece.
This proves that the move is valid. I then reverse my manipulations and go back to the first manipulation position (i.e.
where I landed on the white piece) I then ‘flip’ the white piece over and change it to black .
I continue flipping the white pieces until I reach the black piece again.I set my bool to true to show that the move is
valid and then I exit the function.

After exiting the function and seeing that my bool is true I change the ‘*’ symbol on the board that corresponds to the
players move to that player’s piece (in this case ‘B’)

Checking if Pass is Valid
As stated in the rules a player can make a pass if there is no place for them to move. I use a function to check if an
inputted pass is valid.
I first check if there is at least one colour for each player on the board. If this is the case I then continue more
indepth to see if a move is available for the player.
For example let’s say black entered a pass.
I use a function to search the board for a black piece. One I find a position that has a black piece, I pass that
position into another function. I then proceed to manipulate that position in the same manner as described above but in
reverse. I check all 8 directions around it for a white piece then if I find a white piece in a  certain direction I
continue in that direction. If I don’t reach the edge of the board or encounter a black piece (ie I read an empty space
(‘*’). That means that there is in fact a valid move for black to input. I then print out all the valid moves I find and
then ask Black to input a move again.

Meeting End of Game Requirements
As Stated in the rules. An Othello game can only end when neither players can make a move consecutively or if the board
is full.

To meet this requirement I use functions.
I call these two functions every time before I ask a player for a move.
To check if the board is full I simply loop through the current board and If I find an empty space (‘*). I set a bool to
true. To show that there is still space on the board. To check if there are two consecutively valid passes. I use a
global array of size 60 (60 because there are 60 spaces on the board to be filled) If a valid move was entered. I set
that array index to 0 but if a valid pass was entered I set that array index to 1. If my array had two 1’s side by side
it meant that two valid passes had been entered consecutively. The function would then return false. The game ended when
either of these checks returned false.

Finding The Winner
After the game ended I used a function to count the number of pieces of each player.
The player with the greatest number of pieces on the board won. If they had equal numbers the game ended in a draw.
