// Write a function to find square root of a number.
#include<stdio.h>
#include<math.h>
void fun_sqr(int x){
    printf("The square of the %d is %.2f",x,sqrt(x));
}
int main(){
    int x;
    printf("Enter the number you want to find the squareroot:\t");
    scanf("%d",&x);
    fun_sqr(x);
}