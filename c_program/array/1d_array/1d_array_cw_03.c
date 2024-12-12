#include<stdio.h>
int main(){
    float a[10]={55,51,60,54,78,65,77,45,30,20},temp;
    int i,j;
    for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The greatest no is %.2f\n",a[9]);
    for(i=0;i<10;i++){
        printf("%.2f\t",a[i]);
    }
}