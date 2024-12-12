// 8. WAP to check whether a triangle is isosceles or not?
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the sides of the traingle"<<endl;
    cin>>a>>b>>c;
    cout<<((a==b||b==c||c==a)?"Traingle is isocelous":"traingle is not isocelous");
}