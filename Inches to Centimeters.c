// convert height inches to centimeters using 2.54 * height
#include<stdio.h>
int main()
{
	short inches;
	float centimeters;
	printf("Enter height in inches : ");
	scanf("%d",&inches);
	
	centimeters=2.54*inches;
	
	printf("\n---output---\n");
	printf("Centimeters = %f",centimeters);
}
