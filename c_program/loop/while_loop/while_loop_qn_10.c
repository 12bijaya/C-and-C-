// Write a C program to check whether a Number is Armstrong or not.
//  (for this question check Armstrong condition for three digits numbers like 153,
//  no need check for other digits numbers)
//bijaya
#include<stdio.h>
#include<math.h>
int main(){
    int i=0,num,org_num,check_arm[2],sum=0;
    printf("Enter the number:\t");
    scanf("%d",&num);
    org_num=num;
    while(i<=2){
        check_arm[i]=num%10;
        sum+=pow(check_arm[i],3);
        num/=10;
        i++;
    }
    if(sum==org_num)
        printf("the number is armstrong");
    else
        printf("no is not armstrong");
}
//bijaya