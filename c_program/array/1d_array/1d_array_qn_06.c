// Suppose you got an array a[]={2,6,7,9,12,14,5,7,8,6}. 
// WAP to find the sum & average of all the even numbers of an array
// Bijaya Kumal
#include<stdio.h>
int main(){
    int i=0,a[]={2,6,7,9,12,14,5,7,8,6,100},sum=0,count=0;
    while(a[i]!=100){
        if(a[i]%2==0){
            count++;
            sum+=a[i];
        }
        i++;
    }
    int _average=(sum/count);
    printf("The sum and average of the even numbers in the array %d and %d",sum,_average);
}
// Bijaya Kumal