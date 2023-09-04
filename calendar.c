/*Develop a program that receives the month and year from the
keyboard as integers and prints the calendar in the following
format.

        April 2015 
Mon Tue Wed Thu Fri Sat Sun 
1   2   3   4   5   6   7 
8   9   10  11  12  13  14 
15  16  17  18  19  20  21 
22  23  24  25  26  27  28 
29  30 
Note that according to the Gregorian calendar 01/01/01 was
Monday. With this as the base, the calendar should be generated.*/

#include <stdio.h>

int main() {
    int month, year;

    printf("Enter month (1-12) and year (e.g., 2023): ");
    scanf("%d %d", &month, &year);

    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a valid month (1-12).\n");
        return 1; // Exit with an error code
    }

    printf("\n");

    // Zeller's Congruence algorithm to calculate the day of the week
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int day = 1; // First day of the month
    int m = month;
    int h = (day + 13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
    int dayOfWeek = (h % 7 + 7) % 7; // 0 = Saturday, 1 = Sunday, 2 = Monday, etc.

    // Define the number of days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year (February)
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[2] = 29;

    // Print the calendar header
    printf("%d %d\n", month, year);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");

    // Print leading spaces
    for (int i = 0; i < dayOfWeek; i++)
        printf("    ");

    // Print the days of the month
    for (int dayOfMonth = 1; dayOfMonth <= daysInMonth[month]; dayOfMonth++) {
        printf("%2d  ", dayOfMonth);

        // Move to the next line after Sunday
        if ((dayOfWeek + dayOfMonth) % 7 == 0)
            printf("\n");
    }

    printf("\n");

    return 0;
}