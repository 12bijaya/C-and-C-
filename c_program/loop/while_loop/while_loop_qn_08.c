// Write a C Program to generate a Fibonacci series up to n terms
// Like: 1       2        3            5            8            13          21............... 
//bijaya
#include<stdio.h>
int main(){
    int fabo=1,i=1,n,a=2,b;
    printf("Enter the number of terms:\t");
    scanf("%d",&n);
    while(i<=n){
        printf("%d\t",fabo);
        fabo=fabo+a;
        b=fabo;
        fabo=a;
        a=b;
        i++;
    }

}
//bijaya