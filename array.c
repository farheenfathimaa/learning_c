/*If an array arr contains n elements, then write a program to check if 
arr[ 0 ] = arr[ n-1 ], arr[ 1 ] = arr[ n - 2 ] and so on.*/
#include<stdio.h>
int main(){
    int a[25],i,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        if(a[i]==a[n-i-1]){ printf("a[%d]=a[%d]\n",i,n-i-1);}
        else {printf("a[%d]!=a[%d]\n",i,n-i-1);}
    }
    return 0;
}