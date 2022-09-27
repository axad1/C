#include<stdio.h>
int main()
{
	int n;
	printf("Enter rows: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0, m=n*2; j<m; j++)
		{
			if(i==0 || i==n-1 || j==0 || j==m-1)
			printf("*");
//			else part is very crucial
			else
			printf(" ");
		}
		printf("\n");
	}
}
