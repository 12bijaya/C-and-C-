// Write a C Program to generate a multiplication table of a number entered by user.
//bijaya
#include<stdio.h>
int main(){
    int i=1,n;
    printf("Enter the number you want to find the multiplication table of:\t");
    scanf("%d",&n);
    printf("The nultiplication table of %d is given below \n\n",n);
    while(i<=10){
        printf("___________________________________________________________________________________\n");
        printf("|\t%d\t|\t*\t|\t%d\t|\t=\t|\t%d\t|\n",n,i,n*i);
        i++;
    }
    printf("___________________________________________________________________________________\n");
}
//bijaya