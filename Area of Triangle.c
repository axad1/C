//input base and height and calculate area of triangle area = 1/2 * base *height
#include<stdio.h>
int main()
{
	float area,base,height;
	printf("Enter base : ");
	scanf("%f",&base);
	printf("Enter height : ");
	scanf("%f",&height);
	
	area = 0.5*base*height;
//	print
	printf("\n---output---\n");
	printf("Area = %.2f\n",area);
}
