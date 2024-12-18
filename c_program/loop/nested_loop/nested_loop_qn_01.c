// 1. WAP to take a positive number ’n ‘ from user and, display the factorial of all the number
// from 1 to ’n
#include<stdio.h>
int main(){
    int i,j,num,fact;
    printf("Enter the positive number up to which you want to find the factorial:\t");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        fact=1;
        for(j=1;j<=i;j++){
            fact*=j;
        }
        printf("The factorial of %d is %lld\n",i,fact);
    }
}