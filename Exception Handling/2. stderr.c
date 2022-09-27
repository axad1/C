#include<stdio.h>
#include<errno.h>
int main()
{
	int a,b;
	printf("input dividend : ");
	scanf("%d", &a);
	printf("input divisor : ");
	scanf("%d", &b);
	
	if(b == 0)
	{
		fprintf(stderr, "Division by 0 is not possible!\n");
		return 1;
	}
	printf("%d", a/b);
}
