// 3. Write a C++ program to check whether a number is even or odd.
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter number\n"<<endl;
    cin>>a;
    cout<<(a%2==0?"a is even":"a is odd");
}