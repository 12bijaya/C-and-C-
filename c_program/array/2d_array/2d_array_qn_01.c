// WAP to take elements of matrix as input 
// ( ask user for number of rows and column). 
// Display that matrix in matrix form.
//Bijaya Kumal
#include<stdio.h>
int main(){
    int i,j,x,y;
    printf("How ,any rows and columns do you want:\n");
    scanf("%d%d",&x,&y);
    int a[x-1][y-1];
    printf("Enter the value for the particular position of your matrix:\n");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("Enter the value for[%d] row and [%d] column:\t",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix form according to your data entry is:\n\n\n");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n\n");
    }
}