//  WAP to check whether a number is Armstrong or not? 
// (user can enter any length of integer)
//bijaya
#include<stdio.h>
#include<math.h>
int main(){
    int i=0,num,org_num,sum=0;
    printf("Enter the number:\t");
    scanf("%d",&num);
    org_num=num;
    while(num>0){
        num/= 10;
        i++;
    }
    int check_num[i],count=i;
    num=org_num;
    i=0;
    while(i<count){
        check_num[i]=num%10;
        sum+=pow(check_num[i],count);
        num/= 10;
        i++;
    }
    if(org_num==sum)
        printf("the no is armstrong");
    else
        printf("the no is not armstrong");
}
//bijaya