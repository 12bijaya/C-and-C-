/* WAP which has three functions:  takeintput, calculate_volume, and display_volume. 
From main function call the takeinput function which takes radius and height of a 
cylinder as input. Call calculate_volume function from the body of  takeinput 
function, which calculates the volume of the cylinder. Call display_volume function 
from the body of calculate-volume, which displays the volume of that cylinder. 
(make function types ad per your need) */

#include<stdio.h>
void display_volume(float volume){
    printf("The volume of the cylinder is:%.2f",volume);
}
void calculate_volume(int a,int h){
    float volume=3.14*a*a*h;
    display_volume(volume);
}
void takeinput(){
    printf("Enter the radius and height of the:\n");
    int r,h;
    scanf("%d%d",&r,&h);
    calculate_volume(r,h);
}
int main(){
    takeinput();
    return 0;
}
//Bijaya Kumal
