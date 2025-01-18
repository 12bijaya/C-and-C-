/*WAP to calculate and display area of a circle using a Function, area_calculate(). 
This function should not take any arguments but should return the area of a circle. 
(Without argument, with return type)*/
//Bjaya Kumal
#include<stdio.h>
float pi = 3.14;
float area_calculate(){
    printf("Enter the radius of circle:\n");
    int r;
    scanf("%d",&r);
    float area=pi*r*r;
    return area;
}
int main(){
    printf("the are of the circle is:\t%.2f",area_calculate());
    return 0;
}
//Bijaya Kumal
