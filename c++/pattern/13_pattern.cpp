// 1 1 1 1 1
//  2 2 2 2
//   3 3 3
//    4 4
//     5

#include<iostream>
using namespace std;
int main(){
    int i,j,k,l;
    for(i=0;i<5;i++){
        for(k=0;k<i;k++){
            cout<<" ";
        }
        l=1;
        l+=i;
        for(j=0;j<5-i;j++){
            cout<<l<<" ";
        }
        cout<<endl;
    }
}