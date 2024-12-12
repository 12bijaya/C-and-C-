#include<stdio.h>
int main(){
	int a,b,c;
	printf("Enter the value of a,b,c:\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b){
		if(a>c){
			printf("a is greatest");
		}
		else
			printf("c is greatest");
	}
	else if(b>c){
		if(b>a){
			printf("b is greatest");
		}
		else
			printf("a is greatest");
	}
	else
		printf("c is greatest");
}
