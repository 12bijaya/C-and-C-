#include<stdio.h>
int vote(int y){
    printf("%d",y);
    int age,x=10;
    printf("enter your age\t");
    scanf("%d",&age);
    if(age>=18 && age<=100){
        printf("\nyou can vote\n");
    }
    else if(age>100){
        printf("First make your death ceertificate\n");
    }
    else{
        printf("Child like gaurav and you cannot vote\n");
    }
    return x;
}
int main(){
    int b=10;
   int a = vote(b);
   printf("%d",a);
    return 0;
}
