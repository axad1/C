#include<stdio.h>
int main()
{
	FILE *out;
	out = fopen("text.txt","w");
	if(out == NULL)
	{
		printf("Errorr");
		return 1;
	}
	char str[25];
	printf("Enter string: ");
	gets(str);
	fputs(str,out);
	fclose(out);
}
