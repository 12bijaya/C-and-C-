//  WAP to find the sum of all the digits of a number entered 
// by the user ( 2345==>2+3+4+5=14)
//bijaya
#include<stdio.h>
int main(){
	int i,num,sum=0;
	printf("enter the number:\t");
	scanf("%d",&num);
	while(num>0){
	sum+=num%10;
	num/=10;
	}
	printf("sum of all the digits is :\t%d\n",sum);
}
//bijaya
