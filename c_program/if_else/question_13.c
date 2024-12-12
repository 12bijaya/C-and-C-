//Bijaya Kumal
//  WAP ask user about their height in cm, if it is greater than 160 cm, ask the user about their occupation, and display the height and occupation.
//  Else, (height<160cm), ask their age and display the height and age.
#include<stdio.h>
int main(){
    float height;
    printf("enter your height:\t");
    scanf("%f",&height);
    int age;
    char occupation[10];
    if(height>160)
    {
        printf("Enter your occupation:\t");
        scanf("%s",occupation);
        printf("Your height is %.2f and occupation is %s\n",height,occupation);
    }
    else
    {
        printf("Enter your age:\t");
        scanf("%d",&age);
        printf("Your height is %.2f and occupation is %d\n",height,age);       
    }
}
//Bijaya Kumal