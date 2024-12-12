#include<stdio.h>
int main(){
    int a = 2;
    int *p = &a;
    // int b = p;
    int bp = *p;
    printf("%d\t%d\t%d\t%d",a,*p,bp,p);
}