#include<stdio.h>
int main()
{
	int a[] = {1,4,1,4,5};
	int res = 0;
	for(int i=0; i<sizeof(a)/sizeof(int); i++)
	{
		res = res ^ a[i];
		printf("%d\n", res);
	}
	printf("res = %d", res);
}
