/* Write a Program using Function for calculating total distance travelled by a vehicle 
in t seconds. Where, distance, d= ut+at2 /2; The function should take u , a and t as 
an argument.  And display the distance travelled from inside the function. (Function 
with argument and without return type) */
//Bijaya Kumal
#include<stdio.h>
void _kinematics(float u, int t, float a){
    float s = u*t + a*t*t/2;
    printf("The distance is : %.2f", s);
}
int main(){
    float u,a;
    int t;
    printf("Enter initial velocity, time in motion and average acceleration:\n");
    scanf("%f%d%f",&u,&t,&a);
    _kinematics(u,t,a);
    return 0;
}
//Bijaya Kumal
