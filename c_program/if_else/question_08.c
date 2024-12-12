//Bijaya Kumal
// 8. WAP to check whether a triangle is isosceles or not?
#include<stdio.h>
void main(){
    int a,b,c;
    printf("Input the sides of traingle:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a==b || b==c || a==c)
        printf("Traingle is isoceles traingle");
    else
        printf("Traingle is not isoceles");
    printf("\n");
}
//Bijaya Kumal