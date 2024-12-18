// 6. Write a Cpp program to check whether a year is leap year or not. (with and without using nested if-else)
#include<iostream>
using namespace std;
int main(){
    int year;
    cout<<"Enter the year\t";
    cin>>year;
    if(year%100==0 && year%400!=0){
        cout<<"year is not leap";
    }else if(year%4==0 || year%400==0){
        cout<<"year is leap year";
    }else{
        cout<<"year is no leap";
    }

}