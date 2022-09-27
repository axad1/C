#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//	a pointer char can handle 23 characters with size 0
	char *s = malloc(0);
	printf("size is = %d\n", sizeof(s));	//	sizeis=4
	sscanf("aaaaaaaaaaaaaaaaaaaaaaa", "%s", s);
	puts(s);
	printf("%d\n", strlen(s));
	free(s);
	
	//	-------------------
	
	//	an array char can handle 15 characters with size 0
	char str[0];
	sscanf("aaaaaaaaaaaaaaa", "%s", str);
	printf("size is = %d\n", sizeof(str));
	puts(str);
	printf("%d\n", strlen(str));
}
