//Bijaya Kumal
// 9. WAP to take a character as input and check whether it is an alphabet, digits or other character; display relevant message.
#include<stdio.h>
int main(){
    char a;
    printf("Enter the character:\t");
    scanf(" %c",&a);
    int ascii = a;
    if(ascii>47 && ascii<58)
        printf("Given character is number");
    else if((ascii>64 && ascii<91) || (ascii>96 && ascii<123))
        printf("Given character is alphabet");
    else 
        printf("It is other character");
    printf("\n");
}
//Bijaya Kumal
// #include<stdio.h>
// #include<ctype.h>
// int main(){
//     char ch;
//     printf("Enter character:\t");
//     scanf(" %c",&ch);
//     if(isalpha(ch))
//        printf("alphabet");
//     else if(isdigit(ch))
//         printf("number");
//     else
//         printf("special character");
//     printf("\n");
// }