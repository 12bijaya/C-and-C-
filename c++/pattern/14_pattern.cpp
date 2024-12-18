//                         1

//                 1       2       1

//         1       2       3       2       1

// 1       2       3       4       3       2       1

#include<iostream>
using namespace std;
int main(){
    int i,j,k,l;
    for(i=0;i<4;i++){
        for(j=1;j<4-i;j++){
            cout<<"\t";
        }
        for(k=1;k<=i+1;k++){
            cout<<k<<"\t";
        }
        for(l=k-2;l>=1;l--){
            cout<<l<<"\t";
        }
        cout<<endl<<endl;
    }
}