#include<stdio.h>

// converter
float feet_to_cm(float feet)
{
	return feet * 30.48;
}

// driver
int main()
{
	puts("--- feet to cm ---");
	float feet;
	
	printf("Enter feet: ");
	scanf("%f", &feet);
	
	float cm = feet_to_cm(feet);
	
	printf("cm = %f", cm);
}

