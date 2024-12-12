//Bijaya Kumal
// 3. Write a C program to check whether a number is even or odd.
#include<stdio.h>
int main(){
    int a;
    printf("Enter the number:\t");
    scanf("%d",&a);
    if(a%2==0)
        printf("a is even");
    else
        printf("a is odd");
    printf("\n");
}