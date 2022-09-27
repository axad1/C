#include<stdio.h>
#include<errno.h>
int main()
{
	FILE *in = fopen("rest.txt", "r");
	if(!in)
	{
		printf("Error = %d", errno);
	}
}
