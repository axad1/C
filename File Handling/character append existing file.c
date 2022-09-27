#include<stdio.h>
int main()
{
	FILE *out = fopen("text.txt","a");
	if(!out)
	{
		printf("Errorr");
		return 1;
	}
	fputc('\n',out);
	char ch;
	printf("Enter a character (. to end): ");
	while(ch != '.')
	{
		ch = getchar();
		fputc(ch,out);
	}
	fclose(out);
}
