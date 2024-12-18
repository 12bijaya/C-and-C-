#include<stdio.h>
int main(){
    int a[2][3];
    for(int i=1;i<=2;i++){
        for(int j=1;j<=3;j++){
            printf("Enter the value for a[%d][%d]:\t",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=3;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
