#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	//	https://www.geeksforgeeks.org/size_t-data-type-c-language/
	int n = sizeof(size_t);
	if(n == 4)
	printf("32 bit\n");
	else if(n == 8)
	printf("64 bit\n");
	else
	printf("Other\n");
	
	system("pause");
}
