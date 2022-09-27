#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	int a,b;
	printf("input dividend : ");
	scanf("%d", &a);
	printf("input divisor : ");
	scanf("%d", &b);
	
	if(b == 0)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	printf("%d", a/b);
}
