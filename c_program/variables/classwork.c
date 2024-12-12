// 1. WAP to take two integers as input, calculate and display their sum and product.
// 2. WAP to ask a user about his name, occupation, age, and GPA of SEE. Display those values as output in different line. 
// 3. WAP to take principal, time and rate as an input, calculate and display the simple interest.
// 4. WAP to take two integers as input and display their values. Swap the values of those variables, again display the values of those variable after swapping
// 5. WAP to calculate the volume of a sphere: take value of radius as input from user. Use #define preprocessor to define value of pi.
// 6. WAP to calculate area of a circle, take radius of circle as input. Make use of ‘const’ keyword for the value of pi. (if you don’t know the formula, google it)
#include<stdio.h>
#include<math.h>
#define pi 3.14;
void question1(){
//     int a,b;
//     printf("Enter two integer:\n");
//     scanf("%d%d",&a,&b);
//     printf("the sum is %d\n",a+b);
}
void question2(){
    // int age;
    // char name[10],occupation[10];
    // float gpa;
    // printf("Enter your name, age, occupation and see gpa\n");
    // scanf("%s%d%s%f",name,&age,occupation,&gpa);
    // printf("Your name is\t:%s\nage is:\t%d\noccupation is:\t%s\nand see gpa is:\t%f\n",name,age,occupation,gpa);
}
void question3(){
    // int principal, time;
    // float rate;
    // printf("Enter principal, time(In years) and rate:\n");
    // scanf("%d%d%f",&principal,&time,&rate);
    // float SI = principal*time*rate/100;
    // printf("The simple interest is:\t%f\n",SI);
}
void question4(){
    // int a,b,c;
    // printf("enter the two integer value:\n");
    // scanf("%d%d",&a,&b);
    // printf("the values are %d and %d",a,b);
    // c=a,a=b,b=c;
    // printf("\nthe new values are %d and %d\n",a,b);
}
void question5(){
    // float r;
    // printf("Enter the radius of the sphere[in m]:\t");
    // scanf("%f",&r);
    // float volume=4*r*r*r*pi;
    // float volume1=volume/3;
    // printf("\nThe volume of sphere is:\t%f\n",volume1);
}
void question6(){
    // float r;
    // printf("Enter the radius of the circle[in m]:\t");
    // scanf("%f",&r);
    // float area=r*r*pi;
    // printf("\nThe area of the circle is is:\t%f\n",area);    
}
void question7(){
    // int a,b;
    // printf("Input the divident:\t");
    // scanf("%d",&a);
    // printf("Input the divisor:\t");
    // scanf("%d",&b);
    // printf("The reminder is %d\n",a%b);
    // printf("The quotient is %d\n",a/b);
}
void question8(){
    // int p,t,n;
    // float r;
    // printf("Input principle,rate, time and no of times interest compounded in a year:\n");
    // scanf("%d%f%d%d",&p,&r,&t,&n);
    // printf("The compound interest is:\t%f\n",p*pow((1+r/n),n*t));
}
void question9(){
    int a,b,c,d,e,f;
    printf("In the quadratic equation what is the value of");
    printf("\na:\t");
    scanf("%d",&a);
    printf("\nb:\t");
    scanf("%d",&b);
    printf("\nc:\t");
    scanf("%d",&c);
    d=b*b-4*a*c;
    e= -b+sqrt(d);
    e=e/2*a;
    d= -b-sqrt(d);
     d = d/2*a;
    printf("the roots are %d and %d",d,e);

}
// ascii(){
//     char ch;
//     getc(ch);
//     printf("%d",ch);
// }


int main(){
    // ascii();
    question1();
    question2();
    question3();
    question4();
    question5();
    question6();
    question7();
    question8();
    question9();
}