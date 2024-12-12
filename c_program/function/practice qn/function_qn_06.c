// Make your own pow function.
#include<stdio.h>
int powe(int x,int y){
    int power = 1,i;
    for(i=1;i<=y;i++){
        power*=x;
    }
    return power;
}
void main(){
    printf("Enter the number and power:\n");
    int number,power;
    scanf("%d%d",&number,&power);
    printf("%d power %d is %d\n",number,power,powe(number,power));
}