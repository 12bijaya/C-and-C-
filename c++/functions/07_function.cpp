//function to convert decimal to binary and vice versa
#include<iostream>
using namespace std;
int pow(int a, int n){
    int value=1;
    for(int i=1;i<=n;i++){
        value*=a;
    }
    return value;
}
int binary(int n){
    int sum=0,i=0;
    while(n>0){
        sum+=(n%2*pow(10,i));
        n/=2;
        i++;
    }
    return sum;
}
int decimal(int n){
    int sum=0,i=0;
    while(n>0){
        sum+=(n%10*pow(2,i));
        i++;
        n/=10;
    }
    return sum;
}
int main(){
    int a,base;
    cout<<"Please justify you want to convert decimal to binary(d-b) or binary to decimal(b-d)"<<endl;
    cout<<"Press 2 to convert decimal to binary and 10 to convert binary to decimal"<<endl;
    cin>>base;
    if(base==2){
        cout<<"Enter the number: ";
        cin>>a;
        cout<<"\n\nbinary!\n\n";
        cout<<binary(a);
    }else if(base == 10){
        cout<<"Enter the number: ";
        cin>>a;
        cout<<"\n\ndecimal!\n";
        cout<<decimal(a);
    }else{
        cout<<"Only enter either 2 or 10\n\n******************\n\n\n";
        main();
    }

}