//Bijaya Kumal
// 7. WAP to check whether a triangle is equilateral or not?  Take sides of triangle as input.
#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the sides of the traingle:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a!=b || b!=c ||a!=c)
        printf("Traingle is not equliteral:");
    else
        printf("traingle is equliteral:");
    printf("\n");
}
//Bijaya Kumal