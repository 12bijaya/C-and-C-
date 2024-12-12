//Bijaya Kumal
// 4. Write a C program to check whether a number is negative, positive or zero.
#include<stdio.h>
int main(){
    int a;
    printf("Enter the number:\t");
    scanf("%d",&a);
    if(a<0)
        printf("number is negative");
    else if(a==0)
        printf("number is zero");
    else
        printf("number is positive");
    printf("\n");
}