/*There are 100 records present in a file with the following structure:
struct date
{
int d, m, y ;
} ;
struct employee
{
int empcode[ 6 ] ;
char empname[ 20 ] ;
struct date join_date ;
float salary ;
} ;

Write a program to read these records, arrange them in ascending
order by join_date and write them to a target file.*/
#include <stdio.h>
#include <stdlib.h>

// Define structures for date and employee
struct Date {
    int d, m, y;
};

struct Employee {
    int empcode[6];
    char empname[20];
    struct Date join_date;
    float salary;
};

// Comparison function for sorting employee records by join_date
int compareByJoinDate(const void *a, const void *b) {
    const struct Employee *employeeA = (const struct Employee *)a;
    const struct Employee *employeeB = (const struct Employee *)b;
    
    // Compare join dates (first compare years, then months, and finally days)
    if (employeeA->join_date.y != employeeB->join_date.y) {
        return employeeA->join_date.y - employeeB->join_date.y;
    } else if (employeeA->join_date.m != employeeB->join_date.m) {
        return employeeA->join_date.m - employeeB->join_date.m;
    } else {
        return employeeA->join_date.d - employeeB->join_date.d;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    
    printf("Enter the name of the input file containing employee records: ");
    scanf("%s", inputFileName);
    
    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1; // Exit with an error code
    }
    
    // Read the number of employee records from the input file
    int numEmployees;
    fscanf(inputFile, "%d", &numEmployees);
    
    // Create an array to store employee records
    struct Employee employees[numEmployees];
    
    // Read employee records from the input file
    for (int i = 0; i < numEmployees; i++) {
        fscanf(inputFile, "%d %s %d %d %d %f", employees[i].empcode, employees[i].empname,
               &employees[i].join_date.d, &employees[i].join_date.m, &employees[i].join_date.y, &employees[i].salary);
    }
    
    // Close the input file
    fclose(inputFile);
    
    // Sort employee records by join_date
    qsort(employees, numEmployees, sizeof(struct Employee), compareByJoinDate);
    
    printf("Enter the name of the target file to write sorted records: ");
    scanf("%s", outputFileName);
    
    // Open the target file for writing
    outputFile = fopen(outputFileName, "w");
    
    if (outputFile == NULL) {
        printf("Error opening the target file.\n");
        return 1; // Exit with an error code
    }
    
    // Write the number of sorted employee records to the target file
    fprintf(outputFile, "%d\n", numEmployees);
    
    // Write sorted employee records to the target file
    for (int i = 0; i < numEmployees; i++) {
        fprintf(outputFile, "%d %s %d %d %d %.2f\n", employees[i].empcode, employees[i].empname,
                employees[i].join_date.d, employees[i].join_date.m, employees[i].join_date.y, employees[i].salary);
    }
    
    // Close the target file
    fclose(outputFile);
    
    printf("Sorted employee records have been written to %s.\n", outputFileName);
    
    return 0;
}

