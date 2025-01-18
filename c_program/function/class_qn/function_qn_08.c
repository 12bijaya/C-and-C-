#include<stdio.h>
void fibo(int a){
    int i,b=0,c=1,temp;
    for(i=1;i<=a;i++){
        printf("%d\t",b);
        temp=b;
        b=c;
        c+=temp;

    }
}
int main(){
    printf("Enter the number up to which you want to find the fibo:\t");
    int a;
    scanf("%d",&a);
    fibo(a);
    return 0;
}