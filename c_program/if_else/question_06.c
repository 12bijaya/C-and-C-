
//Bijaya Kumal
// 6. Write a C program to check whether a year is leap year or not. (with and without using nested if-else)
#include<stdio.h>
int main(){
    int a;
    printf("Enter the value of a:\t");
    scanf("%d",&a);
    if (a%100==0 && a%400!=0)
        printf("It is not leap year");
    else if(a%400==0 || a%4==0)
        printf("It is leap year");
    else
        printf("It is not leap year");
    printf("\n");
}
//Bijaya Kumal