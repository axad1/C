/* time complexity
O (n^2)	= worst case: all nums are in descending order
O (n)	= best case: nums already sorted in acsending order
best use in an already sorted list
*/
#include<stdio.h>
int main()
{
	int a[10];
	int size = sizeof(a)/sizeof(a[0]);
	
	// input
	for(int i=size; i>0; i--)
		a[size-i] = i;
	
	// print
	for(int i=0; i<size; i++)
		printf("%d\t",a[i]);
	puts("");
	
	// bubble sort
	for(int i=0; i<size-1; i++)
	{
		int flag = 0;
		for(int j=0; j<size-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
		if(!flag)
			break;
	}
	
	// print
	puts("");
	for(int i=0; i<size; i++)
		printf("%d\t",a[i]);
}
