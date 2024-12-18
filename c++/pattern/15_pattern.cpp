//                      *

//                 *               *

//         *                               *

// *                                               *

//         *                               *

//                 *               *

//                         *

#include<iostream>
using namespace std;
int main(){
    int i,j,k;
    for(i=0;i<4;i++){
        for(j=1;j<4-i;j++){
            cout<<"\t";
        }
        cout<<"*";
        for(k=1;k<=i*2;k++){
            cout<<"\t";
        }
        if(i>=1){
                cout<<"*";
            }
        cout<<"\n\n";
    }
    for(i=0;i<3;i++){
        for(j=0;j<=i;j++){
            cout<<"\t";
        }
        if(i==2){
            cout<<"*";
        }else{
            cout<<"*";
        }
        for(k=1;k<=(4-(i+2))*2;k++){
            cout<<"\t";
        }
        if(i!=2)
            cout<<"*"<<endl<<endl;

    }

}