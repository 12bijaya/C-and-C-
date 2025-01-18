/*WAP to ask a character input one at a time until user hits ‘e’ or ‘E’. If user hits ‘e’ or 
‘E’, endthe program by displaying “End of Program” . Else, continue to ask for 
another character. Display total number of numeric characters that were entered by 
the user before hitting ‘e’ or ‘E’*/
//Bijaya kumal
#include<stdio.h>
#include<string.h>
int main(){
	char ram;
	int count=0;
	while(ram!='e' && ram!='E'){
		puts("Enter the character");
		ram = getchar();
		getchar();
		count++;
	}
	puts("The numbe of character you entered is");
	printf("%d",count);
}
//Bijaya Kumal
