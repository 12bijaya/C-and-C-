//  WAP to check whether a number entered by the user is palindrome or not.
//bijaya
#include<stdio.h>
int main(){
    int check_num,org_num,rev_num=0;
    printf("enter the number you want to check teh palindrome:\t");
    scanf("%d",&check_num);
    org_num=check_num;
    for(;check_num>0;){
        rev_num=rev_num*10+check_num%10;
        check_num/=10;
    }
    if(org_num==rev_num)
        printf("Given no is pallindrome");
    else
        printf("Given no is not a palindrome");
}
//bijaya