#include<stdio.h>
int main(){
    int num,i,j;
    printf("Enter a positive number:\t");
    scanf("%d",&num);
    for(i=1;i<=10;i++){
        printf("\n");
        for(j=1;j<=num;j++){
            printf("%d * %d = %d\t",j,i,i*j);
        }
    }
}