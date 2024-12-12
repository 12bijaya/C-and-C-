//Bijaya Kumal
/* . WAP to take a character as input and if it is an alphabet, convert lower case alphabet to uppercase, and vise-versa.
If the character is other than alphabet display “other character”*/
#include<stdio.h>
int main(){
    char a;
    printf("Enter the character:\t");
    scanf(" %c",&a);
    int ascii=a;
    if(ascii>64 && ascii<89){
        ascii += 32;
        printf(" %c",ascii);
    }
    else if(ascii>96 && ascii<123){
        ascii -= 32;
        printf(" %c",ascii);
    }
    else
        printf(" %c",a);
    printf("\n");
}
//Bijaya Kumal