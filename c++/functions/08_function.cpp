// reversing of the number 
#include<iostream>
using namespace std;
int reverse(int n){
    int count=0,reverse=0;
    while(n>0){
        reverse=reverse*10+n%10;
        n/=10;
    }
    return reverse;
}
int main(){
    int n;
    cout<<"Enter the number which you want to reverse: ";
    cin>>n;
    cout<<"The reverse of "<<n<<" is "<<reverse(n);
    return 0;
}











































































