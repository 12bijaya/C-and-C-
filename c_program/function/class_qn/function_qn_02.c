/* Write a C Program to find the simple interest using the function. 
Where your function takes Principal, Time and Rate as an input and returns the simple interest.*/
#include<stdio.h>
float simple_interest(int p,int t,int r){
    return p*t*r/100;
}
void main(){
    printf("Enter the principle, time and rate\n");
    int p,t;
    float r;
    scanf("%d%d%f",&p,&t,&r);
    printf("The simple interest is %.2f",simple_interest(p,t,r));

}
