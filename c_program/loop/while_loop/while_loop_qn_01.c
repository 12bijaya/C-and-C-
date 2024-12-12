// 1. Write a C program to find the sum of first ‘n’ natural numbers
//bijaya
#include<stdio.h>
int main(){
    int sum=0,i=1,n;
    printf("Enter the number:\t");
    scanf("%d",&n);
    while(i<=n){
        sum = sum + i;
        i++;
    }
    printf("The sum of first %d numberns is %d\n",n,sum);
    
}
//bijaya