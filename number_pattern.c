/*Write a program to produce the following output:
   1
  2 3
 4 5 6
7 8 9 10*/
#include<stdio.h>
int main(){
    int currentNum=1,i,j,numRows=4;
    for(i=1;i<=numRows;i++){
        for(j=1;j<=numRows-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d ",currentNum);
            currentNum++;
        }
        printf("\n");
    }
    return 0;
}