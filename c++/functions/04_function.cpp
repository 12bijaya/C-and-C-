// calculate the ncr binomial cofficient of n and r 
#include<iostream>
using namespace std;
int fact(int n){
    int facto=1;
    for(int i=2;i<=n;i++){
        facto*=i;
    }
    return facto;
}
int _binomial_coefficient(int n, int r){
    double coeff;
    coeff = fact(n)/((fact(n-r))*fact(r));
    return coeff;
}
int main(){
    int n,r;
    cout<<"Enter the value of n and r:\n";
    cin>>n>>r;
    cout<<"The coefficient of bionomial is:\t"<<_binomial_coefficient(n,r)<<endl;
    return 0;
}