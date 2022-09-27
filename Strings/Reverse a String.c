#include<stdio.h>
int main()
{
	char str[] = "Hello Programming";

//	get string lenth
	int len = 0;
	for(int i=0; str[i]!='\0'; i++)
	len++;
	
//	swap till half - 1
	for(int i=0; i<len/2; i++)
	{
		char c = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = c;
	}
	
	puts(str);
}
