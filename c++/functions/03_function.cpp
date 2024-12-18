// calculate the sum of digits in number
#include<iostream>
int _sum(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
using namespace std;
int main(){
    int number;
    cout<<"Enter the number ";
    cin>>number;
    cout<<"The sum of digits in "<<number<<" is "<<_sum(number)<<endl;
}
