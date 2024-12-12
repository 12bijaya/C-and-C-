#include<stdio.h>
void _sum(int* a,int* b){
    printf("The sum of %d and %d is %d\n",*a,*b,(*a)+(*b));
}
void _product(int* a,int* b){
    printf("The product of %d and %d is %d\n",*a,*b,(*a)*(*b));
}
void _average(int* a,int* b){
    printf("The average of %d and %d is %d\n",*a,*b,((*a)+(*b))/2);
}
int main(){
    int a,b;
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    _sum(&a,&b);
    _average(&a,&b);
    _product(&a,&b);
}