// floids traingle
// 1

// 2       3

// 4       5       6

// 7       8       9       10
#include<iostream>
using namespace std;
int main(){
    int i,j,k=1;
    for(i=0;i<4;i++){   
        for(j=0;j<i+1;j++){
            
            cout<<k<<"\t";
            k++;
        }
        int k=j+1;
        cout<<endl<<endl;
    }
}