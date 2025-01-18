/* Make a function named check_palindrome to check whether a number is 
palindrome or not. (Function without argument and without return type) */
//Bijaya Kumal
#include<stdio.h>
#include<stdbool.h>
void pallindrom(){
    printf("Enter the number ");
    int a;
    scanf("%d",&a);
    int rev = 0,org_num=a;
    while(a>0){
        rev=rev*10+a%10;
        a/=10;
    }
    bool b=false;
    if(rev==org_num){
        b=true;
    }
    if(b){
        printf("The number is pallindrome");
    }else{
        printf("The number is not pallindrome");
    }
}
int main(){
	pallindrom();
}
//Bijaya Kumal
