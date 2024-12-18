//Bijaya Kumal
#include<stdio.h>
int main(){
    int i,j,k;
    for(i=1;i<=5;i++){
        for(k=5-i;k>=1;k--){
            printf("\t");
        }
        for(j=1;j<2*i;j++){
            printf("\t*");
        }
        printf("\n\n\n");
    }
}
//Bijaya Kumal