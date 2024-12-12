// WAP to take a positive integers as input, 
// display the sum of all the positive factors of that number.  
//bijaya
#include<stdio.h>
int main(){
    int i=1,n,sum=0;
    printf("Enter the number you want to find the sum of factor:\t");
    scanf("%d",&n);
    if(n>0){
        while(i<=n){
            if(n%i==0){
                sum=sum+i;
            }
            i++;
        }
    }
    else{
        printf("enter the positive number please\n");
        main();
    }
    printf("The sum of the positive factors of %d is %d",n,sum);
}
//bijaya