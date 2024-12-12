// Write a C Program to generate a multiplication table of a
//  number entered by user.
//bijaya
#include<stdio.h>
int main(){
    int i,n;
    printf("Enter the number you want to find the multiplication table of:\t");
    scanf("%d",&n);
    printf("The nultiplication table of %d is given below \n\n",n);
    for(i=1;i<=10;i++){
        printf("___________________________________________________________________________________\n");
        printf("|\t%d\t|\t*\t|\t%d\t|\t=\t|\t%d\t|\n",n,i,n*i);
    }
    printf("___________________________________________________________________________________\n");
}
//bijaya