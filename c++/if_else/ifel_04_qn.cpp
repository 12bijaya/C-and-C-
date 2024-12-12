// 4. Write a C++ program to check whether a number is negative, positive or zero.
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the number"<<endl;
    cin>>a;
    if(a<0){
        cout<<"a is negative"<<endl;
    }else if(a>0){
        cout<<"a is positive"<<endl;
    }else{
        cout<<"no is zero"<<endl;
    }
}