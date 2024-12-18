// WAP to take elements of two matrixes a and b as input, 
// display the sum of those two matrix. 
// (Take number of row and column as input)
// Bijaya Kumal 
#include<stdio.h>
int main(){
    int i,j,x,y;
    printf("How ,any rows and columns do you want:\n");
    scanf("%d%d",&x,&y);
    int a[x-1][y-1],b[x-1][y-1];
    printf("Enter the value for the particular position of your matrix:\n");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("Enter the value for [%d] row [%d] column:\t",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("Enter the value for [%d] row [%d] column:\t",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    printf("The sun of those matrix is:\n");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%d\t",a[i][j]+b[i][j]);
        }
        printf("\n\n");
    }
}