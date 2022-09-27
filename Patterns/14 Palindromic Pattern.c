#include<stdio.h>
int main()
{
	int n;
	printf("Enter rows: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=i; j<n-1; j++)
		printf(" ");
		for(int j=i+1; j>0; j--)
		printf("%d", j);
		for(int j=2; j<=i+1; j++)
		printf("%d", j);
		printf("\n");
	}
}
/* output
   1
  212
 32123
4321234
*/
