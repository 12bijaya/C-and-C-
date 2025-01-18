//WAP to generate a multiplication table of a number using recursion
//Bijaya Kumal
#include<stdio.h>
int sum(int n,int i){
	if(i<=10){
		printf("%d\t*\t%d\t=\t%d\n",n,i,n*i);
		sum(n,i+1);
	}
	else
		return 0;
}
int main(){
        printf("Enter the number:\t");
        int n;
        scanf("%d",&n);
        printf("The multiplication table is \n");
	sum(n,1);
}
//Bijaya Kumal

