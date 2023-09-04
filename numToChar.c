/*
Write a program that receives a 5-digit number and prints it out in
large size as shown below. e.g.. 12122
    # 
   ## 
    #  
    #
  #### 

#####
    #
#####
#    
#####

    # 
   ## 
    #  
    #
  #### 

#####
    #
#####
#    
#####

#####
    #
#####
#    
#####
*/
#include <stdio.h>
void reverseArray(int digit[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = digit[i];
        digit[i] = digit[size - 1 - i];
        digit[size - 1 - i] = temp;
    }
}
// Function to print a large digit
void printLargeDigit(int digit) {
    switch (digit) {
        case 0:
            printf("#####\n");
            printf("#   #\n");
            printf("#   #\n");
            printf("#   #\n");
            printf("#####\n");
            printf("\n");
            break;
        case 1:
            printf("  #  \n");
            printf(" ##  \n");
            printf("  #  \n");
            printf("  #  \n");
            printf("#### \n");
            printf("\n");
            break;
        case 2:
            printf("#####\n");
            printf("    #\n");
            printf("#####\n");
            printf("#    \n");
            printf("#####\n");
            printf("\n");
            break;
        case 3:
            printf("#####\n");
            printf("    #\n");
            printf("#####\n");
            printf("    #\n");
            printf("#####\n");
            printf("\n");
            break;
        case 4:
            printf("#   #\n");
            printf("#   #\n");
            printf("#####\n");
            printf("    #\n");
            printf("    #\n");
            printf("\n");
            break;
        case 5:
            printf("#####\n");
            printf("#    \n");
            printf("#####\n");
            printf("    #\n");
            printf("#####\n");
            printf("\n");
            break;
        case 6:
            printf("#####\n");
            printf("#    \n");
            printf("#####\n");
            printf("#   #\n");
            printf("#####\n");
            printf("\n");
            break;
        case 7:
            printf("#####\n");
            printf("    #\n");
            printf("   # \n");
            printf("  #  \n");
            printf("  #  \n");
            printf("\n");
            break;
        case 8:
            printf("#####\n");
            printf("#   #\n");
            printf("#####\n");
            printf("#   #\n");
            printf("#####\n");
            printf("\n");
            break;
        case 9:
            printf("#####\n");
            printf("#   #\n");
            printf("#####\n");
            printf("    #\n");
            printf("#####\n");
            printf("\n");
            break;
        default:
            printf("Invalid digit: %d\n", digit);
    }
}

int main() {
    int num, digit[5],size=5;

    printf("Enter a 5-digit number: ");
    scanf("%d", &num);

    if (num < 10000 || num > 99999) {
        printf("Please enter a valid 5-digit number.\n");
        return 1;
    }

    printf("\n");

    // Print each digit in large size
    for (int i = 0; i < 5; i++) {
        digit[i]= num % 10;
        num /= 10;
        
    }

    reverseArray(digit, size);
    for (int i=0;i<5;i++)
    printLargeDigit(digit[i]);
    return 0;
}