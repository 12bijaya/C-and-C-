/*Write a C program to find the square of any number using the function (without 
argument & without return type.)
Bijaya Kumal
*/
#include<stdio.h>
void square(int num){
    printf("The square of %d is %d",num,num*num);
}
int main(){
    printf("Enter the number you want to find the square \n");
    int num;
    scanf("%d",&num);
    square(num);
}
//Bijaya Kumal
