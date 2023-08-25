/*Write a general-purpose function to convert any given year into its
Roman equivalent. Use these Roman equivalents for decimal
numbers: 1 – I, 5 – V, 10 – X, 50 – L, 100 – C, 500 – D, 1000 – M.
Example:
Roman equivalent of 1988 is mdcccclxxxviii.
Roman equivalent of 1525 is mdxxv.*/
#include<stdio.h>
void convertToRoman(int year) {
    const char *ro[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char r[20];
    int i=0,ar[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1},res;
    while(year>0){
        res=year%10;
        r[i]=res;
        year=year/10;
        i++;
    }
        for (int j = i - 1; j >= 0; j--) {
        printf("%s", ro[r[j] - 1]);
    }

    printf("\n");
    }


int main(){
    int year;
    printf("Enter a year: ");
    scanf("%d",&year);
    convertToRoman(year);
    return 0;
}