//Bijaya Kumal
// 5. write a C program to check whether a number is divisible by both 5 and 11, or not.
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number:\t");
    scanf("%d",&n);
    if(n%5==0&&n%11==0)
        printf("It is divisible by both 5 and 11");
    else
        printf("It is not divisible by both 5 and 11");
    printf("\n");
}

//Bijaya Kumal