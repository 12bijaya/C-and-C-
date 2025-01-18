/*Write a C program to check whether a number is prime or not using the concept of 
function. For this make a user defined function isPrime ( function with argument & 
without return type)*/
//Bijaya Kumal
#include<stdio.h>
void prime(int a){
    int i,count=0;
    for(i=2;i<=a/2;i++){
        if(a%i==0){
            count++;
        }
    }
    if(count>=2){
        printf("The number is composite");
    }else{
        printf("The number is prime");
    }
}
void main(){
    printf("Enter the number to check the prime number\t");
    int prm;
    scanf("%d",&prm);
    prime(prm);
}
//Bijaya Kumal
