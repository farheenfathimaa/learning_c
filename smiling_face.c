/*Write a program to fill the entire screen with a smiling face. The
smiling face has an ASCII value 1.*/
#include<stdio.h>
#define screen_width 80
#define screen_height 25
int main(){
    int screen[screen_width][screen_height],i,j;
    for(i=0;i<screen_width;i++){
        for(j=0;j<screen_height;j++){
            screen[i][j]=1;
        }
    }
    for(i=0;i<screen_width;i++){
        for(j=0;j<screen_height;j++){
            printf("%c",screen[i][j]);
        }
        printf("\n");
    }
    return 0;
}