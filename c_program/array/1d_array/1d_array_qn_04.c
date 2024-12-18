// WAP to take ‘n’ numbers of integers as input,
// sort that integers in descending order, 
// and display the output in descending order.
// Bijaya Kumal
#include<stdio.h>
int main(){
    printf("Enter how many integer you want to enter:\t");
    int n,i,j;
    scanf("%d",&n);
    int inter[n-1],temp;
    printf("Please carefully enter the value:\n");
    for(i=0;i<n;i++){
        printf("Enter the %d st/nd/rd/th value:\t",i+1);
        scanf("%d",&inter[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(inter[i]<inter[j]){
                temp=inter[i];
                inter[i]=inter[j];
                inter[j]=temp;
            }
        }
    }
    printf("The descendiong order of the data you inputed is:\n");
    for(i=0;i<n;i++){
        printf("%d\t",inter[i]);
    }
}
// Bijaya Kumal