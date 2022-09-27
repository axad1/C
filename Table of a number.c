#include<stdio.h>
int main()
{
	int n;
	printf("Enter number : ");
	scanf("%d",&n);
	int j = 1;
	while(j<=10)
	{
		printf("%d * %d = %d\n",n,j,n*j);
		j++;
	}
}
