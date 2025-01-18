#include<stdio.h>
int var_choose;
void _input(){
    printf("please enter no you choose:\t");
    scanf("%d",&var_choose);
}
int main(){
    printf("You must have at least one information of the user: \n\n");
    printf("Email,\t\t Phone no, \t\t common username\n\n");
    printf("\n\n\n*************************************************************************************************************\n\n\n");
    printf("You must enter 1 for email, 2 for phone no, 3 for common username, 4 for photo and 5 for if you have all\n\n\n");
    printf("###################################################################################################################\n\n\n");
    _input();
}