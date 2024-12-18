#include<iostream>
using namespace std;
int main(){
    // 10. WAP to take an alphabet as input and check whether it is a vowel or a consonant.
    char alpha[5]={'a','e','i','o','u'},inpu;
    cout<<"Input the alphabet only"<<endl;
    cin>>inpu;
    bool check = false;
    for(int i=0;i<5;i++){
        if(alpha[i]==inpu){
            check = true;
            break;
        }
    }
    if(check==true){
        cout<<"The given input is vowel"<<endl;
    }else{
        cout<<"The given input is consonant"<<endl;
    }

}