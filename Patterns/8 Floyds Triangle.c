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
			printf("%-2d", x);
			x++;
		}
		printf("\n");
	}
}
/* output
1
23
456
78910
*/
