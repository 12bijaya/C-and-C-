#include <stdio.h>
int main()
{
    int a=1, b=2, c;
    printf("a is %d\nb is %d",a,b);
    c=a,a=b,b=c;
    printf("\na is %d\nb is %d\n",a,b);
}
