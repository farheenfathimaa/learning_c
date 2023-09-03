/*Define a function getfloat( ), which would receive a numeric string
from the keyboard, convert it to a float value and return the float to
the calling function.*/
#include <stdio.h>
#include <stdlib.h>

float getFloat(char *str) {
    float result;
    if (sscanf(str, "%f", &result) == 1) {
        return result;
    } else {
        printf("Invalid input. Please enter a valid numeric string.\n");
        exit(1);  // Exit the program with an error code
    }
}

int main() {
    char input[100];  // Assuming a maximum input length of 99 characters
    float n;

    printf("Enter a numeric string: ");
    scanf("%s", input);

    n = getFloat(input);

    printf("The number is %.2f\n", n);

    return 0;
}