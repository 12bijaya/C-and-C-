//Bijaya Kumal
// 12. WAP to take three integers as input, and check whether those three integers can form a triangle or not, display the message.
#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter three integers:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a+b<=c||b+c<=a||a+c<=b)
        printf("the given integers cannot form traingles\n");
    else
        printf("Given integers can form traingle\n");
}
//Bijaya Kumal