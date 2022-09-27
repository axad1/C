#include<stdio.h>
int main()
{
	int n;
	printf("Enter rows: ");
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}
}
/* output
1
12
123
1234
*/
