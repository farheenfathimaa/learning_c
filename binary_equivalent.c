/*A positive integer is entered through the keyboard. write a recursive function to find the binary equivalent of this number.*/
#include <stdio.h>

void binary(int n) {
    if (n == 0) {
        return;
    } else {
        binary(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    printf("Binary equivalent: ");
    if (n == 0) {
        printf("0");
    } else {
        binary(n);
    }
    
    printf("\n");
    return 0;
}
