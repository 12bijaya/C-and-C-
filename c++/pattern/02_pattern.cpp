// A       B       C       D

// A       B       C       D

// A       B       C       D

// A       B       C       D

#include<iostream>
using namespace std;
int main(){
    int i,j;
    for(i=0;i<4;i++){
        char ch = 'A';
        for(j=0;j<4;j++){
            cout<<ch<<'\t';
            ch++;
        }
        cout<<endl<<endl;
    }
}