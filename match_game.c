/*Write a program for a matchstick game being played between the
computer and a user. Your program should ensure that the
computer always wins. Rules for the game are as follows:
 There are 21 matchsticks.
 The computer asks the player to pick 1, 2, 3, or 4 matchsticks.
 After the person picks, the computer does its picking.
 Whoever is forced to pick up the last matchstick loses the game.*/
#include<stdio.h>
int main(){
    int total=21,uc;
    printf("Hey there!! let's play an interesting game!\n");
    while(total>0){
    printf("Remaining matchsticks: %d\n", total);
    printf("pick up 1,2,3 or 4 matches\n");
    scanf("%d",&uc);
    if(uc>4||uc<1){
        printf("invalid choice, pick again");
        continue;
    }
    total-=uc;
    if(total<=0){
        printf("You chose the last match, computer wins!");
        break;
    }
    int cc=(total-1)%5;
    if(cc==0)
        cc=1;
    printf("Computer picks %d matchsticks.\n", cc);
    total-=cc;
    if(total<=0){
        printf("computer chose the last match, you win!");
        break;
    }
    }
    return 0;
}