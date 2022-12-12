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
	if(low<high)
	{
		int pivot = partition(a, low, high);
		quicksort(a, low, pivot-1);
		quicksort(a, pivot+1, high);
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
