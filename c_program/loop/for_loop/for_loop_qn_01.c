// 1. Write a C program to find the sum of first ‘n’ natural numbers
//bijaya
#include<stdio.h>
int main(){
    int sum=0,i,n;
    printf("Enter the number:\t");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        sum = sum + i;
    }
    printf("The sum of first %d numberns is %d\n",n,sum);
    
}
//bijaya