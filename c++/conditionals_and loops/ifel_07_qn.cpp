// 7. WAP to check whether a triangle is equilateral or not?  Take sides of triangle as input.
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the sides length of the traingle"<<endl;
    cin>>a>>b>>c;
    cout<<((((a+b)>c)&&((b+c)>a)&&((c+a)>b))?"given side is of traingle":"Given side is not of traingle");
}