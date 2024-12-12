#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of input\n");
    scanf("%d",&n);
    int age[n];
    printf("Enter the input\t");
    for(int i=0;i<n;i++){
        scanf("%d",&age[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\t",age[i]);
    }
}
   