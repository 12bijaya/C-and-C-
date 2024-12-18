// *                                                       *

// *       *                                       *       *

// *       *       *                       *       *       *

// *       *       *       *       *       *       *       *

// *       *       *       *       *       *       *       *

// *       *       *                       *       *       *

// *       *                                       *       *

// *                                                       *

#include<iostream>
using namespace std;
int main(){
    int l,i,j,k;
    for(i=0;i<4;i++){
        for(j=0;j<=i;j++){
            cout<<"*\t";
        }
        for(j=0;j<(3-i)*2;j++){
            cout<<"\t";
        }
        for(j=0;j<=i;j++){
            cout<<"*\t";
        }
        cout<<endl<<endl;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4-i;j++){
            cout<<"*\t";
        }
        for(j=0;j<(i)*2;j++){
            cout<<"\t";
        }
        for(j=0;j<4-i;j++){
            cout<<"*\t";
        }
        cout<<endl<<endl;
    }

}