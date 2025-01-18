//WAP to check whether a number is prime or not using recursion
//Bijaya Kumal
#include<stdio.h>
#include<stdbool.h>
bool sum(int n,int count, int i){
	if(i>=n/2){
		if(n%i==0){
			count++;
        		if(count==2){
				return false;
			}
		}
		else{
			sum(n,count,i+1);
		}
	}
	return true;
}
int main(){
        printf("Enter the number:\t");
        int n;
        scanf("%d",&n);
        if(sum(n,1,1)){
		printf("The number is composite");
	}else{
		printf("The number is prime");
	}
}
//Bijaya Kumal
