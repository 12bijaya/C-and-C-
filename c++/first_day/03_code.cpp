// 1. WAP to take two integers as input, calculate and display their sum and product.
// 2. WAP to ask a user about his name, occupation, age, and GPA of SEE. Display those values as output in different line. 
// 3. WAP to take principal, time and rate as an input, calculate and display the simple interest.
// 4. WAP to take two integers as input and display their values. Swap the values of those variables, again display the values of those variable after swapping
// 5. WAP to calculate the volume of a sphere: take value of radius as input from user. Use #define preprocessor to define value of pi.
// 6. WAP to calculate area of a circle, take radius of circle as input. Make use of ‘const’ keyword for the value of pi. (if you don’t know the formula, google it)
#include<iostream>
#include<cmath>
#define pi 3.14
using namespace std;
void sum_product(){
    int a,b;
    cout<<"Enter two integer\n";
    cin>>a>>b;
    int sum = a+b,product=a*b;
    cout<<"\nThe sum of two numbers is "<<sum<<"\nThe product of two numbers is "<<product<<endl;
}
void details(){
    char name[10],occupation[10];
    int age;
    float gpa;
    cout<<"Enter name, occupation\n";
    cin>>name>>occupation;
    cout<<"\nEnter you age and gpa\n";
    cin>>age>>gpa;
    cout<<"Your name is "<<name<<"\nage is "<<age<<"\noccupation is "<<occupation<<"\nand gpa in see is "<< gpa <<endl;

}
void simple_interest(){
    int p,t;
    float r;
    cout<<"Enter principle, time and rate:\n";
    cin>>p>>t>>r;
    cout<<"The simpel interest is:\t"<<p*t*r/100;

}
void sphere(){
    int r;
    float volume;
    cout<<"Enter the radius of sphere ";
    cin>>r;
    volume = pow(r,3)*4*pi/3;
    cout<<"The area is "<< volume;
}
void circle(){
    int r;
    cout<<"Enter the radius of circle ";
    cin>>r;
    cout<<"The area of circle is "<< pow(r,2)*pi;
}
int main(){
    // sum_product();
    // details();
    // simple_interest();
    // sphere();
    circle();

    return 0;
}