/*Write a function that receives variable number of arguments,
where the arguments are the coordinates of a point. Based on the
number of arguments received, the function should display type of
shape like a point, line, triangle, etc., that can be drawn.*/
#include <stdio.h>
#include <stdarg.h>

void determineShape(int numArgs, ...) {
    if (numArgs == 0) {
        printf("No coordinates provided. Cannot determine shape.\n");
        return;
    } else if (numArgs == 2) {
        printf("Shape: Point\n");
    } else if (numArgs == 4) {
        printf("Shape: Line\n");
    } else if (numArgs % 2 == 0) {
        printf("Shape: Triangle\n");
    } else {
        printf("Unsupported number of coordinates. Cannot determine shape.\n");
    }
}

int main() {
    determineShape(2, 5, 6);            // Point
    determineShape(4, 2, 3, 5, 4);      // Line
    determineShape(6, 1, 2, 3, 4, 5, 6);  // Triangle
    determineShape(8, 1, 2, 3, 4, 5, 6, 7, 8);  // Unsupported
    return 0;
}
