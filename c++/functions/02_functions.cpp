// calculate n factorial
#include<iostream>
using namespace std;
int _facto(int n){
    int facto=1,i;
    for(i=n;i>=2;i--){
        facto*=i;
    }
    return facto;
}
int main(){
    cout<<"Enter the number you wnat to find the factorial: ";
    int n;
    cin>>n;
    cout<<"The factorial of "<<n<<" is "<<_facto(n)<<endl;
}
