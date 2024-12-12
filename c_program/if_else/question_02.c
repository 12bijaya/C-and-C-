//Bijaya Kumal
// 2. Write a C program to find maximum between three numbers.
#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the numbers:\n");
    scanf("%d%d%d",&a,&b,&c);
    if (a>b && a>c){
        printf("a is the greatest\n");
    }
    else if(b>c && b>a){
        printf("b is greatest\n");
    }
    else
    printf("c is greatest\n");
}