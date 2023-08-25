/*Write a C function to evaluate the series:
sin(x) = x - (x^3/ 3!) + (x^5/ 5!) - (x^7/ 7!)...
up to 10 terms.*/

#include<stdio.h>
#include<math.h>
int fact(int n){
    if (n == 0 || n == 1) {
        return 1;
    }
    return n*fact(n-1); 
}
int main(){
    float res=0.0;int x;
    printf("Enter a value 'x' for solving sin(x): ");
    scanf("%d",&x);
    for(int n=1;n<=10;n++){
        if(n%2==0){
            res=-(pow(x,n)/(float)fact(n));
        }
        else{
            res=+(pow(x,n)/(float)fact(n));
        }
    }
    printf("%f",res);
    return 0;
}








