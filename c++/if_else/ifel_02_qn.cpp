// 2. Write a C++ program to find maximum between three numbers.
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter three value\n";
    cin>>a>>b>>c;
    if(a>b&&a>c)
        cout<<"a is the greatest"<<endl;
    else if(b>a&&b>c)
        cout<<"b is greatest"<<endl;
    else if(c>a&&c>b)
        cout<<"c is greatest"<<endl;
    else
        cout<<"all are equal";
}