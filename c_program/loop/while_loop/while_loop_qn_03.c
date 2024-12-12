// 3. WAP to find sum of all the numbers that fall within
//  the range entered by the user.
//bijaya
#include<stdio.h>
int main(){
    int sum=0,i,n1,n2;
    printf("ENter the range:\n");
    scanf("%d%d",&n1,&n2);
    i=n1;
    while(i<n2){
        sum+=i;
        i++;
    }
    printf("The sum is %d",sum);
}
//bijaya