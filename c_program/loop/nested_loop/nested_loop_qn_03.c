//  WAP to take a number as input from the user. Find and display the sum of all the digits of 
// that number until that number becomes a single digit number. (3689==>3+6+8+9 ==
// 26==2+6==>8) 
#include<stdio.h>
int main(){
    int num,sum=0;
    printf("Enter the number:\t");
    scanf("%d",&num);
    while(num>0){
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        if((sum/10)>0){
            num=sum;
            sum=0;
        }
        else
            printf("The expected output is:\t%d\n",sum);
    }

}