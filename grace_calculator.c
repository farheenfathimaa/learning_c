/*Write a program to find the grace marks for a student using switch. The user should enter the class obtained by the student and the
number of subjects he has failed in. note that total number of subjects are 5. Use the following logic:
     If the student gets first class and the number of subjects he failed in is greater than 3, then he does not get any grace.
      Otherwise the grace is of 5 marks per subject.
     If the student gets second class and the number of subjects he failed in is greater than 2, then he does not get any grace.
      Otherwise the grace is of 4 marks per subject.
     If the student gets third class and the number of subjects he failed in is greater than 1, then he does not get any grace.
      Otherwise the grace is of 3 marks.*/
#include<stdio.h>
int main(){
    int failed_sub,grace,total=5,i=0;
    char class[10];
    printf("enter the class obtained by the student and the number of subjects he has failed in: ");
    scanf("%s%d",class,&failed_sub);
    switch(class[i]){
        case 'f': printf("class: first\nsubjects failed:%d\n",failed_sub);
                      if(failed_sub<3){ 
                      grace=(total-failed_sub)*5;
                      printf("grace= %d",grace);
                      }
                      else printf("the student does not receive any grace");
                      break;
        case 's': printf("class: second\nsubjects failed:%d\n",failed_sub);
                      if(failed_sub<2){ 
                      grace=(total-failed_sub)*4;
                      printf("grace= %d",grace);
                      }
                      else printf("the student does not receive any grace");
                      break;
        case 't': printf("class: third\nsubjects failed:%d\n",failed_sub);
                      if(failed_sub<1){ 
                      grace=(total-failed_sub)*5;
                      printf("grace= %d",grace);
                      }
                      else printf("the student does not receive any grace");
                      break;
        default: printf("the student does not receive any grace");
    }
    return 0;
}