//Bijaya Kumal
// 14. WAP to take percentage of a student as input, display his/her division based on their percentage.
//  (>80: distinction, 60-79: First division, 45-60: second division, 32-45: third division, and <32 : fail)
#include<stdio.h>
int main(){
    float p;
    printf("Enter your percentage:\t");
    scanf("%f",&p);
    if(p>=80){
        printf("\nDinction:");
    }
    else if (p>=60)
    {
        printf("\nfirst Division");
    }
    else if (p>=40)
    {
        printf("\n second division");
    }
    else 
        printf("fail");
    printf("\n");
}
//Bijaya Kumal