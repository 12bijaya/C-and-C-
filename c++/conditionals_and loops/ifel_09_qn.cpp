// 9. WAP to take a character as input and check whether it is an alphabet, digits or other character; display relevant message.
#include<iostream>
using namespace std;
int main(){
    char a;
    cout<<"Enter the character"<<endl;
    cin>>a;
    if((a>='a'&&a<='z')&&(a>='A'&&a<='Z')){
        cout<<"\nAlphabet!\n";
    }else if(a>='0'&&a<='9'){
        cout<<"\nNumber!\n";
    }else{
        cout<<"\nOther Character!\n";
    }
}