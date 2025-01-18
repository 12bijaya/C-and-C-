//WAP to generate a Fibonacci series with the help of recursive function
//Bijaya Kumal
#include<stdio.h>
void fibo(int a,int b, int c,int temp,int i){
	if(i<=a){
	printf("%d\t",b);
	temp=b;
	b=c;
	c+=temp;
	i++;
	fibo(a,b,c,temp,i);
	}
}
int main(){
	int a;
	printf("Enter the number up to which you want the fibonacii series:\t");
	scanf("%d",&a);
	fibo(a,0,1,0,1);
}
//Bijaya Kumal
