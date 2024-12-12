// swap 2 number 
#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int main(){
    int a,b;
    printf("Enter the two number you want to swap:\n");
    scanf("%d%d",&a,&b);
    printf("The value of a and b is %d and %d\n",a,b);
    swap(&a,&b);
    printf("The value of a and b after swapping is %d and %d",a,b);
}