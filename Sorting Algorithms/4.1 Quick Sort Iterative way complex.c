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
	// create an auxiliary stack
	int stack[2];
	
    // initialize top of stack
	int top = -1;
	
    // push initial values of l and h to stack
	stack[++top] = low;
	stack[++top] = high;
	
	// keep popping from stack while is not empty
	while(top>=0)
	{
		// pop high and low
		high = stack[top--];
		low = stack[top--];
		
		// set pivot element at its correct position in sorted array
		int pivot = partition(a, low, high);
		
		// if there are elements on left side of pivot then push left side to stack
		if(pivot-1 > low)
		{				
			stack[++top] = low;
			stack[++top] = pivot-1;
		}
		// if there are elements on right side of pivot, then push right side to stack
		else if(pivot+1 < high)
		{
			stack[++top] = pivot+1;
			stack[++top] = high;
		}
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
