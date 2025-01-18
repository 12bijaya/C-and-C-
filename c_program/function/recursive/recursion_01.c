//WAP to find the sum of n natural numbers using recursive function
//Bijaya Kumal
#include<stdio.h>
int sum(int n){
	if (n==1)
		return 1;
	else
		return n+sum(n-1);
}
int main(){
	printf("Enter the number:\t");
	int n;
	scanf("%d",&n);
	printf("The sum of first%d number is %d",n,sum(n));
}
//Bijaya Kumal
