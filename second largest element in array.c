#include<stdio.h>
int main()
{
	int a[] = {5,4,3,2,1};
	int size = sizeof(a)/sizeof(int);
	int largest, second;
	
	if(a[0] < a[1])
	{
		largest = a[1];
		second = a[0];
	}
	else
	{
		largest = a[0];
		second = a[1];
	}
	
	for(int i=2; i<size; i++)
	{
		if(a[i] > largest)
		{
			second = largest;
			largest = a[i];
		}
		else if(a[i] > second && a[i] != largest)
		{
			second = a[i];
		}
	}
	
	printf("largest = %d\n", largest);
	printf("second largest = %d\n", second);
}
