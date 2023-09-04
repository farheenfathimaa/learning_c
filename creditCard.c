/*A Credit Card number is usually a 16-digit number. A valid Credit
Card number would satisfy a rule explained below with the help of a
dummy Credit Card number—4567 1234 5678 9129. Start with the
rightmost - 1 digit and multiply every other digit by 2.
4 5 6 7 1 2 3 4 5 6 7 8 9 1 2 9
8 12 2 6 10 14 18 4
Then subtract 9 from any number larger than 10. Thus we get:
8 3 2 6 1 5 9 4
Add them all up to get 38.
Add all the other digits to get 42.
Sum of 38 and 42 is 80. Since 80 is divisible by 10, the Credit Card
number is valid.
Write a program that receives a Credit Card number and checks
using the above rule whether the Credit Card number is valid.*/
#include <stdio.h>
#include <string.h> // Include the string.h library for strlen function

int main() {
    char cardNumber[17];
    int sum = 0;
    int isSecondDigit = 0;

    printf("Enter a 16-digit Credit Card number: ");
    scanf("%s", cardNumber);

    // Check if the input is exactly 16 characters long
    if (strlen(cardNumber) != 16) {
        printf("Invalid Credit Card number (not 16 digits).\n");
        return 1; // Exit with an error code
    }

    for (int i = 15; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (isSecondDigit) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        isSecondDigit = !isSecondDigit;
    }

    if (sum % 10 == 0)
        printf("Valid Credit Card number.\n");
    else
        printf("Invalid Credit Card number.\n");

    return 0;
}