// this solution is without recursion and simple. Greate Achievement
/* time complexity
O (nlogn) = worst case:
O (nlogn) = best case:
*/
#include<stdio.h>
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int index = low-1;
	
	for(int i=low; i<high; i++)
	{
		if(a[i]<pivot)
		{
			index++;
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
	index++;
	int temp = a[index];
	a[index] = a[high];
	a[high] = temp;
	return index;
	
}
void quicksort(int a[], int low, int high)
{	
	while(1)
	{	
		// set pivot element at its correct position in sorted array
		int pivot = partition(a, low, high);
		
		// if there are elements on left side of pivot then push left side to stack
		if(pivot-1 > low)				
			high = pivot-1;
			
		// if there are elements on right side of pivot, then push right side to stack
		else if(pivot+1 < high)
			low = pivot+1;
			
		else
			break;
	}
	
}

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
	
	// quick sort
	quicksort(a, 0, size-1);
	
	// print
	for(int i=0; i<size; i++)
		printf("%d\t", a[i]);
	puts("");
}
