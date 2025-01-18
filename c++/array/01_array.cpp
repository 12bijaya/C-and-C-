#include<iostream>
#include<climits>
using namespace std;
int min(int num[]){
    int minimum = INT_MAX;
    for(int i=0;i<5;i++){
        if(minimum>num[i]){
                minimum=num[i];
        }
    }
    return minimum;
}
int max(int num[]){
    int maxium = INT_MIN;
    for(int i=0;i<5;i++){
        if(maxium<num[i]){
                maxium=num[i];
        }
    }
    return maxium;
}
int main(){
    int num[5];
    cout<<"enter the calue in the array\n";
    for(int i=0;i<5;i++){
        cin>>num[i];
    }
    cout<<"The maximum value and minimum values are "<<max(num)<<" and "<<min(num)<<" respectively";
}