/*Consider a currency system in which there are notes of seven denominations, namely, Re. 1, Rs. 2, Rs. 5, Rs. 10, Rs. 50, Rs. 100.
If a sum of Rs. N is entered through the keyboard, write a program to compute the smallest number of notes that will combine 
to give Rs.N.*/
#include<stdio.h>
int main(){
    int x;
    printf("enter the cost: ");
    scanf("%d",&x);
    while(x>0){
        switch(x){
            case 100:
                x-=100;
                printf("1 note of Rs. 100\n");
                break;
            case 50:
                x-=50;
                printf("1 note of Rs. 50\n");
                break;
            case 10:
                x-=10;
                printf("1 note of Rs. 10\n");
                break;
            case 5:
                x-=5;
                printf("1 note of Rs. 5\n");
                break;
            case 2:
                x-=2;
                printf("1 note of Rs. 2\n");
                break;
            case 1:
                x-=1;
                printf("1 note of Rs. 1\n");
                break;
            default:
                printf("Invalid amount or combination of notes.\n");
                return 1;
        }
    }
    return 0;
}
/*#include <stdio.h>

int main() {
    int amount;
    printf("Enter the amount in rupees: ");
    scanf("%d", &amount);

    printf("The minimum number of notes:\n");

    while (amount > 0) {
        switch (amount) {
            case 100:
                printf("1 note of Rs. 100\n");
                amount -= 100;
                break;
            case 50:
                printf("1 note of Rs. 50\n");
                amount -= 50;
                break;
            case 10:
                printf("1 note of Rs. 10\n");
                amount -= 10;
                break;
            case 5:
                printf("1 note of Rs. 5\n");
                amount -= 5;
                break;
            case 2:
                printf("1 note of Rs. 2\n");
                amount -= 2;
                break;
            case 1:
                printf("1 note of Rs. 1\n");
                amount -= 1;
                break;
            default:
                printf("Invalid amount or combination of notes.\n");
                return 1; 
        }
    }

    return 0;
}*/
