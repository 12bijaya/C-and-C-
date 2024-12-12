//Bijaya Kumal
// 16. WAP to calculate area of different shapes (circle, square, or a rectangle) based on the choice entered by the user. (1 for circle, 2 for square, and 3 for a rectangle)
#include<stdio.h>
#include<math.h>
#define pi 3.14
int main(){
    char a;
    printf("enter 1 for area of circle 2 for area of square and 3 for area of rectangle:\t");
    scanf(" %c",&a);
    if(a!='1'&&a!='2'&&a!='3'){
        printf("\n\nChoose 1 or 2 or 3 or ctrl+z to exit\n");
        main();
    }
    else if(a=='1'){
        float r;
        printf("Enter the radius of circle in m:\t");
        scanf("%f",&r);
        printf("The area of the circle is:\t%.2f m^2\n",pow(r,2)*pi);
    }
    else if(a=='2'){
        int l;
        printf("Enter the length of square in m:\t");
        scanf("%d",&l);
        printf("The area of the square is:\t%.2f m^2\n",pow(l,2));
    }
    else{
        int l,b;
        printf("Enter the length and breadth of the rectangle in m:\n");
        scanf("%d%d",&l,&b);
        printf("The area of rectangle is :\t%d m^2\n",l*b);
    }
}
//Bijaya Kumal