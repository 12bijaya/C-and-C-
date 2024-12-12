// . WAP to take a range of number from user, and display all the prime numbers that lie 
// within that range.
#include<stdio.h>
int main(){
    int range_1,range_2,i,j,count;
    printf("Enter the range for prime numbers:\n");
    scanf("%d%d",&range_1,&range_2);
    printf("The prime numbers are:\n");
    for(i=range_1;i<=range_2;i++){
        count=0;
        for(j=1;j<=i/2;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count<2){
            printf("%d\t",i);
        }
    }
}