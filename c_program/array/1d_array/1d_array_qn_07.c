// WAP to take n elements of an array, 
// and display all the prime numbers of an array and  
// find sum of those prime numbers.
// Bijaya Kumal
#include<stdio.h>
int main(){
    printf("How many elements you want to store in the array:\t");
    int n;
    scanf("%d",&n);
    int _array[n-1],sum=0,i,j;
    printf("Enter the elements in the array:\n");
    for(i=0;i<n;i++){;
        scanf("%d",&_array[i]);
    }
    printf("The list of the prime numbers are:\n");
    for(i=0;i<n;i++){
        int count = 0;
        for(j=1;j<=_array[i]/2;j++){
            if(_array[i]%j==0){
                count++;
            }
        }
        if(count<=2){
            printf("%d\t",_array[i]);
            sum+=_array[i];
        }
    }
    printf("\nand the sum is %d",sum);
}