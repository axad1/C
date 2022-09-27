#include<stdio.h>
#include<io.h>
int main()
{
	char *c = getcwd("hey", 5);
	puts(c);
}
