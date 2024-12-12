//  Write a C Program to Find whether a number entered by
//  a user is Prime or not
//bijaya
#include<stdio.h>
int main(){
    int i,prime_check,count=0;
    printf("Enter the number you want to check:\t");
    scanf("%d",&prime_check);
    if(prime_check==1){
        printf("The given no is neither priime nor composite");
        return 0;
    }
    for(i=1;i<=prime_check/2;i++){
        if(prime_check%i==0){
            count+=1;
        }
    }
    if(count>=2){
        printf("The given number is composite");
    }
    else
        printf("given no is prime");
}
//bijaya



















