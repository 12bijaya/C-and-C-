// 2. Write a C Program to find the factorial of a number entered 
// by user using loop
//bijaya
#include<stdio.h>
int main(){
    int i=1,n,fact=1;
    printf("Enter the number you want to find the factorial:\t");
    scanf("%d",&n);
    for(i=n;i>1;i--){
        fact*=i;
    }
    printf("The factorial of %d is %d \n",n,fact);
}
//bijaya