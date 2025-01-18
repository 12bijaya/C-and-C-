/*suppose you have a string char name[]="@Ne123pal456#". WAP to copy and 
display only the alphabets to another string name2[]. you can use any header files 
and bulit-in functions as per your need.*/
//bijaya Kumal
#include<stdio.h>
int main(){
	char name[]="@Ne123pal456",name2[9];
	int i=0,j=0;
	while(name[i]!='\0'){
		if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')){
			name2[j]=name[i];
			j++;
		}
		i++;
	}
	name[j]='\0';
	printf("%s",name2);
	return 0;
}
//bijaya Kumal
