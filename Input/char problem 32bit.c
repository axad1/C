#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//	a pointer char can handle 19 characters with size 0	(old compiler)
	//	a pointer char can handle 15 characters with size 0	(new compiler)
	char *s = malloc(0);
	printf("size is = %d\n", sizeof(s));	//	sizeis=4
	sscanf("aaaaaaaaaaaaaaaa", "%s", s);
	puts(s);
	printf("%d\n", strlen(s));
	free(s);
	
	//	------------------
	
	//	an array char can handle 11 characters with size 0 (old compiler)
	//	an array char can handle 0 characters with size 0 (new compiler)
	char str[0];
	sscanf("aaaaaaaaaaa", "%s", str);
	printf("size is = %d\n", sizeof(str));
	puts(str);
	printf("%d\n", strlen(str));
}
