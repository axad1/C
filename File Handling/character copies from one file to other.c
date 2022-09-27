#include<stdio.h>
int main()
{
	FILE *in,*out;
	if((in=fopen("text.txt","r")) == NULL || (out = fopen("asad.txt","w")) == NULL)
	{
		printf("Errorr");
		return 1;
	}
	char ch;
	while((ch=fgetc(in)) != EOF)
	fputc(ch,out);
	fclose(out);
	fclose(in);
}
