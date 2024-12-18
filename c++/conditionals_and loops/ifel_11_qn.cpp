//sum of all number     from 1 to n which is divisible by 3
#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout<<"Enter the value of n:\t";
    cin>>n;
    cout<<"The sum of all numbers up to N divisible by 3 is :"<<endl;
    for(int i=1;i<=n;i++){
        if(i%3==0){
            sum+=i;
        }
    }
    cout<<sum<<endl;
}