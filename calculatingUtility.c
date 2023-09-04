/*Write a program that can be used at command prompt as a
calculating utility. The usage of the program is shown below.
C> calc <switch> <n> <m>
Where, n and m are two integer operands. switch can be any one of
the arithmetic or comparison operators. If arithmetic operator is
supplied, the output should be the result of the operation. If
comparison operator is supplied then the output should be True or
False.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: calc <switch> <n> <m>\n");
        return 1;
    }

    char *operation = argv[1];
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    int result;

    if (strcmp(operation, "+") == 0) {
        result = n + m;
    } else if (strcmp(operation, "-") == 0) {
        result = n - m;
    } else if (strcmp(operation, "*") == 0) {
        result = n * m;
    } else if (strcmp(operation, "/") == 0) {
        if (m == 0) {
            printf("Error: Division by zero\n");
            return 1;
        } else {
            result = n / m;
        }
    } else if (strcmp(operation, "<") == 0) {
        printf("%s\n", n < m ? "True" : "False");
        return 0; // Exit after comparison, as there's no numerical result.
    } else if (strcmp(operation, ">") == 0) {
        printf("%s\n", n > m ? "True" : "False");
        return 0; // Exit after comparison, as there's no numerical result.
    } else if (strcmp(operation, "==") == 0) {
        printf("%s\n", n == m ? "True" : "False");
        return 0; // Exit after comparison, as there's no numerical result.
    } else {
        printf("Invalid operator: %s\n", operation);
        return 1;
    }

    printf("%d\n", result); // Print the numerical result for arithmetic operations.

    return 0; // Return 0 to indicate successful execution.
}