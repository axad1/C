//	table of a number
#include<stdio.h>
void table(int n)
{
	int j = 1;
	while(j<=10)
	{
		printf("%d * %d = %d\n",n,j,n*j);
		j++;
	}
}
int main()
{
	int n;
	printf("Enter number : ");
	scanf("%d",&n);
	table(n);
}
