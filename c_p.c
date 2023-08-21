//cartesian_polar.c
/*Write a program to receive Cartesian co-ordinates (x, y) of a point and convert them into polar co-ordinates (r, si).
Hint: r = sqrt ( x2 + y2) and si=tan-1 ( y / x )*/
#include<stdio.h>
#include<math.h>
int main(){
    float x,y,r,si;
    printf("enter the coordinates x and y: ");
    scanf("%f%f",&x,&y);
    r=sqrt((x*x)+(y*y));
    si=pow(tan(y/x),-1);
    printf("The reqiured polar coordinates are: (%f,%f)",r,si);
    return 0;
}