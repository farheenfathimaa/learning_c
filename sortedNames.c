/*Suppose a file contains student’s records with each record
containing name and age of a student. Write a program to read these records and display them in sorted order by name.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student records
struct Student {
    char name[50];
    int age;
};

// Comparison function for sorting student records by name
int compareByName(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    return strcmp(studentA->name, studentB->name);
}

int main() {
    FILE *file;
    char filename[100];
    
    printf("Enter the name of the file containing student records: ");
    scanf("%s", filename);
    
    // Open the file for reading
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }
    
    struct Student students[100];
    int numStudents = 0;
    
    // Read student records from the file
    while (fscanf(file, "%s %d", students[numStudents].name, &students[numStudents].age) == 2) {
        numStudents++;
    }
    
    // Close the file
    fclose(file);
    
    // Sort the student records by name
    qsort(students, numStudents, sizeof(struct Student), compareByName);
    
    // Display the sorted records
    printf("Sorted Student Records by Name:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Age: %d\n", students[i].name, students[i].age);
    }
    
    return 0;
}
