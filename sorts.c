/*implement the selection sort,bubble sort and insertion sort algorithms on a set of 5 numbers*/
#include<stdio.h>

void selectionSort(int* a, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The array sorted by selection sort is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int* a, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("The array sorted by bubble sort is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int* a, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    printf("The array sorted by insertion sort is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[5], n = 5;
    printf("Enter the 5 numbers to be sorted: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    bubbleSort(a, n);
    insertionSort(a, n);
    return 0;
}