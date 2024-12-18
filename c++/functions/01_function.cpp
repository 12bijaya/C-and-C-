//calculate the sum from 1 to n
#include<iostream>
using namespace std;
void _sum(){
    int n;
    cout<<"ENter the number up to which you want to find the sum"<<endl;
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<"The sum is : "<<sum<<endl;
}
int main(){
    _sum();
    return 0;
}