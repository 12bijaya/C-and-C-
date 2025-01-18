//WAP to find the factorial of a number n using recursion
//Bijaya Kumal
#include<stdio.h>
int sum(int n){
        if (n==1)
                return 1;
        else
                return n*sum(n-1);
}
int main(){
        printf("Enter the number:\t");
        int n;
        scanf("%d",&n);
        printf("The factorial of %d is %d",n,sum(n));
}
//Bijaya Kumal
