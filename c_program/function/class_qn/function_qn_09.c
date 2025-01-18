/*WAP to calculate the area of circle and rectangle. Make two functions each to 
calculate area of circle and rectangle. In main function ask user to enter 1 to 
calculate area of circle and 2 for rectangle. On the basis of user choice, call the 
related function. Those function should return area to the main; display area from 
the main function. (Without argument, with return type)*/
//Bijaya Kumal
#include<stdio.h>
float pi = 3.14;
float area_rect(){
    printf("Enter the length and breadthof rectangle:\t");
    int l,b;
    scanf("%d%d",&l,&b);
    return (l*b);
}
float area_circle(){
    printf("Enter the radius of the circle:\t");
    int r;
    scanf("%d",&r);
    return (pi*r*r);
}
float inpu(){
    int choose;
    printf("Enter 1 to find the area of circle\nEnter 2 to find the area of the rectangle\n");
    printf("Enter your choice:\t");
    scanf("%d",&choose);
    if(choose==2){
        return area_rect();
    }else if(choose==1){
        return area_circle();
    }else{
        printf("Plese only enter either 1 or 2");
        inpu();
    }
}
int main(){
    printf("The area of is %.2f",inpu());
    return 0;
}
//Bijaya Kumal
