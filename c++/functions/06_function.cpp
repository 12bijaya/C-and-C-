#include<iostream>
using namespace std;
void print_fibo(int n){
    int a=0,b=1,temp;
    for(int i=1;i<=n;i++){
        cout<<a<<"\t";
        temp=a;
        a=b;
        b+=temp;
    }
}
int main(){
    int n;
    cout<<"Enter the valuse up to which you want to print fibonasis series: ";
    cin>>n;
    cout<<"The list of fibonacii series are:"<<endl;
    print_fibo(n);

}