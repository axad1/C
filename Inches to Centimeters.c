// convert height inches to centimeters using 2.54 * height
#include<stdio.h>

// converter
float inches_to_cm(float inches){
	return inches * 2.54;
}

// driver
int main()
{
	puts("--- inches to cm ---");
	float inches;
	printf("Enter inches: ");
	scanf("%f", &inches);
	float cm = inches_to_cm(inches);
	printf("Centimeters = %f", cm);
}

