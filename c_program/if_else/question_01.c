//Bijaya Kumal
// 1. Write a C program to find maximum between two numbers.

#include<stdio.h>
int main(){
    int a,b;
    printf("enter the value of a and b:\n");
    scanf("%d%d",&a,&b);
    if(a>b)
        printf("a_[%d] is greatest",a);
    else
        printf("b_[%d] is greatest",b);
    printf("\n");
}
