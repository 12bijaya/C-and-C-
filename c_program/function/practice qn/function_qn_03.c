// Function to calculate n factorial (using recursion)
#include<stdio.h>
int facto=1;
int fact(int n){
    if(n>1){
        facto = n * fact(n-1);
    }
    else
        return facto;
}
int main(){
    printf("Enter the number you want to find the factorial:\t");
    int n;
    scanf("%d",&n);
    printf("The factorial of the %d is %d\n",n,fact(n));
}