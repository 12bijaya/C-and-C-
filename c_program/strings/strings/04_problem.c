/*WAP to take one number at a time as input from user until user hits zero (0). End 
the program when user hits 0, display the sum of all the even numbers that were 
entered by the user before hitting 0
Bijaya Kumal
*/
#include<stdio.h>
#include<string.h>
int main(){
	int a,sum=0;
	printf("Enter the number and enter 0 to exist\n");
	while(a!=0){
		scanf("%d",&a);
		if(a%2==0){
			sum+=a;
		}
	}
	printf("The sum is: %d",sum);
}
//Bijaya Kumal
