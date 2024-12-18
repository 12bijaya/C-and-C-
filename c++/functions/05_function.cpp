#include<iostream>
using namespace std;
bool check_prime(int n){
    bool a = true;
    int check=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            check++;
        }
    }
    if(check>=2){
        a=false;
    }
    return a;
}
void print_prime(int n){
    for(int i=2;i<=n;i++){
        if(check_prime(i)){
            cout<<"\t"<<i;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number up to which you want to check : ";
    cin>>n;
    cout<<endl<<"The list of prime numbers are: "<<endl;
    print_prime(n);

}