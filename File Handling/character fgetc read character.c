#include<stdio.h>
int main(void)
{
	FILE *in = fopen("text.txt","r");
	char ch;
	if(!in)
	{
		printf("Errorr");
		return 1;
	}
	while(ch != EOF)
	{
		ch = fgetc(in);
		putchar(ch);
//		printf("%c",ch);
	}
	fclose(in);
	return 0;
}
