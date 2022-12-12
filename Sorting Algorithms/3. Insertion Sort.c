/* time complexity
O (n^2)	worst case:	all nums are descending order
O (n)	best case: already sorted in ascending
best use in already sorted list
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
	
	// insertion sort
	for(int i=1; i<size; i++)
	{
		int j, temp = a[i];
		for(j=i-1; j>=0 && a[j]>temp; j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
	
	// print
	for(int i=0; i<size; i++)
		printf("%d\t", a[i]);
}
