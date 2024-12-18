#include<iostream>
using namespace std;
int main(){
    int i,j,k;
    for(i=0;i<5;i++){
        char ch='A';
        for(k=0;k<i;k++){
            cout<<"\t";
        }
        ch+=i;
        for(j=0;j<=5-i;j++){
            cout<<ch<<"\t  ";
        }
        cout<<endl<<endl;
    }
}