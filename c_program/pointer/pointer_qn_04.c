#include<stdio.h>
void reverse(int* x, int b){
    int i,j,temp;
    for(i=0;i<b;i++){
        for(j=b-1;j>=0;j--){
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }
}
int main(){
    printf("how namy elements you want to print in the array:\t");
    int a;
    scanf("%d",&a);
    int array[a],i;
    printf("Enter the value in the array:\n");
    for(i=0;i<a;i++){
        scanf("%d",&array[i]);
    }
    printf("The value of array you entered is:\n");
    for(i=0;i<a;i++){
        printf("%d\t",array[i]);
    }
    reverse(array,a);
    printf("\nThe reverse value of array you entered is:\n");
    for(i=0;i<a;i++){
        printf("%d\t",array[i]);
    }


}