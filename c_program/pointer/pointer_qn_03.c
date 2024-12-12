#include<stdio.h>
void mani(int *a, int* b){
    if(*a>*b)
        printf("A is greater\n");
    else if(*b>*a)
        printf("B is greater\n");
    else
        printf("both are equal \n");
}
int main(){
    int a,b;
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    mani(&a,&b);
}