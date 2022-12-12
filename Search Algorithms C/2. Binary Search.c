#include<stdio.h>
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
	int start=0, end=4;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(x == a[mid])
		{
			printf("found");
			break;
		}
		else if(x > a[mid])
			start = mid+1;
		else
			end = mid-1;
	}
	
}
