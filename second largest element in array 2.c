#include<stdio.h>
int main()
{
	int a[] = {5,4,3,2,1,10,9,8,7,5,10};
	int size = sizeof(a)/sizeof(int);
	int largest, second;
	
	largest = a[0];
	for(int i=0; i<size; i++)
	{
		if(a[i] > largest)
		{
			largest = a[i];
		}
	}
	
	second = a[0];
	for(int i=0; i<size; i++)
	{
		if(a[i] > second && a[i] != largest)
		{
			second = a[i];
		}
	}
	
	printf("largest = %d\n", largest);
	printf("second largest = %d\n", second);
}
