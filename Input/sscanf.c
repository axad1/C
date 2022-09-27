#include<stdio.h>
int main()
{
	char c[0];
	
	//	space will be skipped
	sscanf("Hello,World", "%s", c);
	
	puts(c);
	
}
