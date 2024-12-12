// WAP to take a positive integers as input,
// display the sum of all the positive factors of that number.  
//bijaya
#include<stdio.h>
int main(){
    int i,n,sum=0;
    printf("Enter the number you want to find the sum of factor:\t");
    scanf("%d",&n);
    if(n>0){
        for(i=1;i<=n;i++){
            if(n%i==0){
                sum=sum+i;
            }
        }
    }
    else{
        printf("enter the positive number please\n");
        main();
    }
    printf("The sum of the positive factors of %d is %d",n,sum);
}
//bijaya