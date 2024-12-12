//Bijaya Kumal
// 10. WAP to take an alphabet as input and check whether it is a vowel or a consonant.
#include<stdio.h>
#include<ctype.c>
int main(){
    char a;
    printf("Enter the character:\t");
    scanf(" %c",&a);
    a=tolower(a);
    if( a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        printf("Inputed character is vowel");
    else
        printf("given character is consonant");
    printf("\n");
}
//Bijaya Kumal
