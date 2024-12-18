// A       B       C

// D       E       F

// G       H       I
#include<iostream>
using namespace std;
int main(){
    int i,j;
    for(i=0;i<7;i+=3){
        for(j=i;j<i+3;j++){
            char ch='A';
            ch+=j;
            cout<<ch<<"\t";
        }
        cout<<endl<<endl;
    }
}