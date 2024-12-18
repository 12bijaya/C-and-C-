//  5. write a Cpp program to check whether a number is divisible by both 5 and 11, or not.
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter the number:\t";
    cin>>a;
    cout<<((a%11==0 && a%5==0)?"Divisible\n":"Non divisible");
}