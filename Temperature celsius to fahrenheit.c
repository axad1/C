// temperature celsius to fahrenheit using F = 9/5 * C + 32
#include<stdio.h>
int main()
{
	float cels,fahren;
	printf("Enter temperature in celsius : ");
	scanf("%f",&cels);
	
	fahren=9.0/5.0 * cels + 32;
	printf("\n---output---\n");
	printf("Fahrenheit = %.2f",fahren);
	
}
