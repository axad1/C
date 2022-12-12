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
	
	int s;
	printf("Enter search: ");
	scanf("%d", &s);
	
	// search
	for(int i=0; i<5; i++)
	{
		if(a[i] == s)
		{
			printf("found");
		}
	}
	
}
