//Bijaya Kumal
// 15. Write a program that determines the winner of a rock-paper-scissors game based on user input and displays the result using if-else statements. 
// (Google the rule of this game. Write program to take inputs from two users , user1 and user2 and determine who wins the game based on their choice)
#include<stdio.h>
int main(){
    char user_1,user_2;
    printf("Input must be r for rock, p for paper and s for scissor only\n");
    printf("Enter the input of the user1:\t");
    scanf(" %c",&user_1);
    printf("Ehter the input of the user2:\t");
    scanf(" %c",&user_2);
    if((user_1=='r'&&user_2=='s')||(user_1=='p'&&user_2=='r')||(user_1=='s'&&user_2=='p'))
        printf("user1 is winnner\n");
    else if((user_2=='r'&&user_1=='s')||(user_2=='p'&&user_1=='r')||(user_2=='s'&&user_1=='p'))
        printf("user2 is winnner\n");
    else
        printf("Noone has win");
    printf("\n");
}
//Bijaya Kumal