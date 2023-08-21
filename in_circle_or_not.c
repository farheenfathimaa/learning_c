/*Given the coordinates (x, y) of center of a circle and its radius, write a c program that will determine whether a point lies inside the circle, on the circle or outside the circle. (Hint: Use sqrt( ) and pow( ) functions)*/
#include<stdio.h>
#include<math.h>
int main(){
    float x1,y1,x2,y2,r,d;
    printf("enter the coordinates of the center of the circle: ");
    scanf("%f%f",&x1,&y1);
    printf("enter the radius: ");
    scanf("%f",&r);
    printf("enter the coordinates of the point: ");
    scanf("%f%f",&x2,&y2);
    d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    if(d==r)
    printf("the point is on the circle");
    else if (d<r)
    printf("the point is inside the circle");
    else
    printf("the point is outside the circle");
    return 0;
}