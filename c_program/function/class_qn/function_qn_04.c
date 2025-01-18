/*Write a C program to find the sum of n natural numbers using the concept of 
function. The function must take ‘n’ as input and should return total sum. (function 
with argument and return type)*/
//Bijaya Kumal
#include<stdio.h>
int _sum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
void main(){
    printf("Enter the number:\t");
    int n;
    scanf("%d",&n);
    printf("The sum of first %d natural numbers is %d",n,_sum(n));
}	
//Bijaya Kumal
