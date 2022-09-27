#include<stdio.h>
int main()
{
	char a[20];
	char str[] = "Hello World";
	
//	copy a string from another string
//	read formatted string
//	return total number of characters

	int n = sprintf(a,"%s",str);
	
	printf("%s\n", a);
	printf("%d", n);
}
