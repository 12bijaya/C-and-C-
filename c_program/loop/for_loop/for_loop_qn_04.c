// 4. Write a C program to find the sum of all the even numbers,
//  and all the odd numbers “separately” within the range of 
// number entered by user ( range is like : from 20 to 40)
#include<stdio.h>
//bijaya
int main(){
    int n1,n2,sum_e=0,sum_o=0,i;
    printf("Enter the range of number firsty and second number:\n");
    scanf("%d%d",&n1,&n2);
    for(i=n1;i<=n2;i++){
        if(i%2==0){
            sum_e=sum_e+i;
        }
        else{
            sum_o=sum_o+i;
        }
    }
    printf("the sum of odd number is %d and even no is %d\n",sum_o,sum_e);
}
//bijaya