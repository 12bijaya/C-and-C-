#include<iostream>
using namespace std;
int main(){
    int i,j,k;
    for(i=1;i<=5;i++){
        for(k=0;k<i;k++){
            cout<<"\t";
        }
        for(j=0;j<=5-i;j++){
            cout<<i<<"\t";
        }
        cout<<endl<<endl;
    }
}