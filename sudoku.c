/*Sudoku is a popular number-placement puzzle (refer Figure 14.9).
The objective is to fill a 9×9 grid with digits so that each column,
each row, and each of the nine 3×3 sub-grids that compose the grid
contains all of the digits from 1 to 9. The puzzle setter provides a
partially completed grid, which typically has a unique solution. One
such solution is given below. Write a program to check whether the
solution is correct or not.
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9*/
#include <stdio.h>
#include <stdbool.h>

// Constants for the Sudoku grid size
#define N 9

// Function to check if a Sudoku row, column, or sub-grid is valid
bool isValid(int board[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int y = 0; y < N; y++) {
        if (board[y][col] == num) {
            return false;
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x + startRow][y + startCol] == num) {
                return false;
            }
        }
    }

    // If the number is not found in the row, column, or sub-grid, it's valid
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            // Find an empty cell
            if (board[row][col] == 0) {
                // Try filling the cell with a number from 1 to 9
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        // If the number is valid, fill the cell
                        board[row][col] = num;

                        // Recursively try to solve the rest of the puzzle
                        if (solveSudoku(board)) {
                            return true; // If a solution is found, return true
                        }

                        // If the current configuration doesn't lead to a solution, backtrack
                        board[row][col] = 0;
                    }
                }
                return false; // If no valid number can be placed, backtrack
            }
        }
    }
    return true; // If all cells are filled, the puzzle is solved
}

int main() {
    int board[N][N] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    if (solveSudoku(board)) {
        printf("Sudoku solution is valid:\n");
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                printf("%2d ", board[row][col]);
            }
            printf("\n");
        }
    } else {
        printf("No valid solution found.\n");
    }

    return 0;
}
