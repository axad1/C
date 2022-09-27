#include<stdio.h>
int main()
{
	FILE *in = fopen("asad.txt","r");
	char c[20];
	
	fread(c,sizeof(c),1,in);
	printf("%s", c);
}
