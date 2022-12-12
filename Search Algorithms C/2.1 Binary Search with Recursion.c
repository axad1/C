#include<stdio.h>
int search(int arr[], int x, int start, int end)
{
	if(start>end)
		return -1;
		
	int mid = (start+end)/2;
	
	if(x==arr[mid])
		return mid;
	
	if(x > arr[mid])
		return search(arr, x, mid+1, end);
	
	return search(arr, x, start, mid-1);
	
}
int main()
{
	int a[5];
	// input
	for(int i=0; i<5; i++)
		a[i] = i+1;
		
	// print
	for(int i=0; i<5; i++)
		printf("%d\t", a[i]);
		
	int x;
	printf("Enter search: ");
	scanf("%d", &x);
	
	// search
	int index = search(a,x,0,4);
	printf("index = %d\n", index);
	
}
