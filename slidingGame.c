/*Very often in fairs we come across a puzzle that contains 15 
numbered square pieces mounted on a frame. These pieces can be 
moved horizontally or vertically. A possible arrangement of these 
pieces is shown:
1 4 15 7 
8 10 2 11 
14 3 6 13 
12 9 5  
As you can see there is a blank at bottom right corner. Implement 
the following procedure through a program:
Draw the boxes as shown above. Display the numbers in the above 
order. Allow the user to hit any of the arrow keys (up, down, left, or 
right). If you are using Turbo C/C++, use the library function 
gotoxy( ) to position the cursor on the screen while drawing the 
boxes. If you are using Visual Studio then use the following function 
to position the cursor:

#include <windows.h>
void gotoxy ( short col, short row )
{
HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
COORD position = { col, row } ;
SetConsoleCursorPosition ( h, position ) ;
}


If user hits say, right arrow key then the piece with a number 5 
should move to the right and blank should replace the original
position of 5. Similarly, if down arrow key is hit, then 13 should 

move down and blank should replace the original position of 13. If 

left arrow key or up arrow key is hit then no action should be taken.
The user would continue hitting the arrow keys till the numbers 
aren’t arranged in ascending order.
Keep track of the number of moves in which the user manages to 
arrange the numbers in ascending order. The user who manages it 
in minimum number of moves is the one who wins.
How do we tackle the arrow keys? We cannot receive them using 
scanf( ) function. Arrow keys are special keys which are identified 
by their ‘scan codes’. Use the following function in your program. It 
would return the scan code of the arrow key being hit. The scan 
codes for the arrow keys are:
up arrow key – 72 down arrow key – 80
left arrow key – 75 right arrow key – 77

# include <conio.h>
int getkey( )
{
int ch ;
ch = getch( ) ;
if ( ch == 0 )
{
ch = getch( ) ;
return ch ;
}
return ch ;
}*/
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printPuzzle(int puzzle[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == 0)
                printf("    ");
            else
                printf("%2d  ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int puzzle[4][4] = {
        {1, 4, 15, 7},
        {8, 10, 2, 11},
        {14, 3, 6, 13},
        {12, 9, 5, 0}
    };
    
    int blankRow = 3, blankCol = 3;
    int moves = 0;
    
    while (1) {
        system("cls");
        
        printf("Moves: %d\n\n", moves);
        printPuzzle(puzzle);
        
        
        
        char move;
        scanf(" %c", &move);
        
        int newRow = blankRow, newCol = blankCol;
        
        if (move == 'w' && blankRow > 0) // Up
            newRow--;
        else if (move == 's' && blankRow < 3) // Down
            newRow++;
        else if (move == 'a' && blankCol > 0) // Left
            newCol--;
        else if (move == 'd' && blankCol < 3) // Right
            newCol++;
        
        if (newRow != blankRow || newCol != blankCol) {
            swap(&puzzle[blankRow][blankCol], &puzzle[newRow][newCol]);
            blankRow = newRow;
            blankCol = newCol;
            moves++;
        }
        if (puzzle[3][3] == 0)
            break;
    }

    printf("\nCongratulations! You solved the puzzle in %d moves.\n", moves);

    return 0;
}