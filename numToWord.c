/*Write a program that receives an integer (less than or two
digits in length) and prints out the number in words. For example, if
the number input is 42, then the output should be Forty Two.*/
 #include <stdio.h>

// Function to convert a 2-digit number to words
void convertToWords(int num) {
    const char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (num < 10) {
        printf("%s\n", ones[num]);
    } else if (num < 20) {
        const char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        printf("%s\n", teens[num - 10]);
    } else {
        int ten = num / 10;
        int one = num % 10;
        printf("%s%s\n", tens[ten], ones[one]);
    }
}

int main() {
    int num;

    printf("Enter a 2-digit number (10-99): ");
    scanf("%d", &num);

    if (num < 10 || num > 99) {
        printf("Invalid input. Please enter a 2-digit number.\n");
        return 1; // Exit with an error code
    }

    printf("In words: ");
    convertToWords(num);

    return 0;
}