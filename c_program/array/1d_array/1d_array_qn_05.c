// Suppose you have an array with elements {2,5,6,1,7,8,9,12,13,14}.
// Take an integer as input from user and check whether that integer 
// is present in the given list of not. Display the relevant message.
// Bijaya Kumal
#include<stdio.h>
int main(){
    int a[]= {2,5,6,1,7,8,9,12,13,14},_check=0,_input,i=0;
    printf("enter the number you want to check in the library:\t");
    scanf("%d",&_input);
    while(a[i]!=14){
        if(_input==a[i])
            _check++;
        i++;
    }
    if(_check==1 || _input==14)
        printf("The %d is available in the dictionary\n",_input);
    else
        printf("The %d is not available in the dictionary\n",_input);
}
// Bijaya Kumal