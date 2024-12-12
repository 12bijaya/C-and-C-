// a. Write a function to find sum of digits of a number.
#include<stdio.h>
int sum_su=0;
void sum( int num){
    int numbr = num;
    while(num>0){
        sum_su+=num%10;
        num/=10;
    }
    printf("The sum of the digits of %d is %d\n",numbr,sum_su);
}
int main(){
    printf("Enter the number you want to find the sum of it's digit:\t");
    int num;
    scanf("%d",&num);
    sum(num);
}