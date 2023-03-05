#include<stdio.h>
int main()
{
	int a[5];
	int size = sizeof(a)/sizeof(a[0]);
	
	// insert
	for(int i=size; i>0; i--)
		a[size-i] = i ;
		
	// print
	for(int i=0; i<size; i++)
		printf("%d\t", a[i]);
	puts("");
		
	// sorting
	int index, temp, low=0, high=size-1;
	label:
	index = low-1;
	for(int i=low; i<high; i++)
	{	
		if(a[i] < a[high])
		{
			index++;
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
	index++;
	temp = a[high];
	a[high] = a[index];
	a[index] = temp;
		
	if(index-1 > low)
	{
		high = index-1;
		goto label;
	}
	else if(index+1 < high)
	{
		low = index+1;
		goto label;
	}
	
	// print
	for(int i=0; i<size; i++)
		printf("%d\t", a[i]);
}
