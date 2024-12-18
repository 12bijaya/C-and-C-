// 1       2       3

// 4       5       6

// 7       8       9

#include<iostream>
using namespace std;
int main(){
    int i,j;
    for(i=1;i<=7;i+=3){
        for(j=i;j<i+3;j++){
            cout<<j<<"\t";
        }
        cout<<endl<<endl;
    }
}