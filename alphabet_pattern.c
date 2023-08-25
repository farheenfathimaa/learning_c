/*Write a program to produce the following output:
A                         A 
A B                     B A
A B C                 C B A
A B C D             D C B A
A B C D E         E D C B A
A B C D E F     F E D C B A
A B C D E F G G F E D C B A*/

#include <stdio.h>

int main() {
    int numRows = 7;
    char currentChar,arr[50];

    for (int i = 0; i < numRows; i++) {
        currentChar = 'A';

        // Print characters in increasing order
        for (int j = 0; j <= i; j++) {
            printf("%c ", currentChar);
            currentChar++;
        }

        // Print spaces
        int numSpaces = 2 * (numRows - i - 1);
        for (int j = 0; j < numSpaces; j++) {
            printf("  ");
        }

        // Print characters in decreasing order
        
        for (int j = 0; j <= i; j++) {
            currentChar--;
            if (currentChar >= 'A') {
                printf("%c ", currentChar);
            }
        }

        printf("\n");
    }

    return 0;
}
