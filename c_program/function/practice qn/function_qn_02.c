// Function to calculate square of a number
#include<stdio.h>
int square(int x){
    int sqr = x*x;
    return sqr;
}
int main(){
    printf("Enter the number you want to find the square:\t");
    int x;
    scanf("%d",&x);
    printf("The square of the %d is %d\n",x,square(x));
}