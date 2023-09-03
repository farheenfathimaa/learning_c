/*Write down macro definitions for the following:
1. To test whether a character is a small case letter or not.
2. To test whether a character is a upper case letter or not.
3. To test whether a character is an alphabet or not. Make use of
the macros you defined in 1 and 2 above.
4. To obtain the bigger of two numbers.*/
#include <stdio.h>
#include <ctype.h>

// 1. To test whether a character is a small case letter or not.
#define isLowerCase(c) (c >= 'a' && c <= 'z')

// 2. To test whether a character is an upper case letter or not.
#define isUpperCase(c) (c >= 'A' && c <= 'Z')

// 3. To test whether a character is an alphabet or not.
#define isAlphabet(c) (isLowerCase(c) || isUpperCase(c))

// 4. To obtain the bigger of two numbers.
#define max(x, y) ((x > y) ? x : y)

int main() {
    char c;
    int x, y;

    printf("Enter a character: ");
    scanf(" %c", &c);

    if (isAlphabet(c)) {
        if (isLowerCase(c)) {
            printf("Given character is a lowercase alphabet.\n");
        } else {
            printf("Given character is an uppercase alphabet.\n");
        }
    } else {
        printf("Given character is not an alphabet.\n");
    }

    printf("Enter two numbers for comparison: ");
    scanf("%d %d", &x, &y);

    int result = max(x, y);
    printf("%d is greater.\n", result);

    return 0;
}
