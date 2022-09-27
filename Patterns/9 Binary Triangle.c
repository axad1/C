#include<stdio.h>
int main()
{
	int n,x=1;
	printf("Enter rows: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if((i+j) % 2 == 0)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
}
/* output
1
01
101
0101
*/
