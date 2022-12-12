/* time complexity
O (n^2) = worst case 
O (n^2) = best case: all nums are in descending order
no best use condition;
*/
#include<stdio.h>
int main()
{
	int a[10];
	int size = sizeof(a)/sizeof(a[0]);
	
	// input
	for(int i=size; i>0; i--)
		a[size - i] = i;
	
	// print
	for(int i=0; i<size; i++)
		printf("%d\t", a[i]);
	puts("");
	
	// selection sort
	for(int i=0; i<size-1; i++)
	{
		int min = i;
		for(int j=i+1; j<size; j++)
		{
			if(a[j] < a[min])
				min = j;
		}
		if(min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	
	// print
	for(int i=0; i<size; i++)
		printf("%d\t", a[i]);
	puts("");
	
}
