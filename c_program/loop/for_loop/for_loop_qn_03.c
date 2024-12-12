// 3. WAP to find sum of all the numbers that
//  fall within the range entered by the user.
#include<stdio.h>
//bijaya
int main(){
    int sum=0,i,n1,n2;
    printf("ENter the range:\n");
    scanf("%d%d",&n1,&n2);
    for(i=n1;i<n2;i++){
        sum+=i;
    }
    printf("The sum is %d",sum);
}//bijaya
//bijaya
//bijaya