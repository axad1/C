#include<stdio.h>
int main()
{
	FILE *in = fopen("asad.txt", "r");
	FILE *out = fopen("text.txt", "w");
	
	for(char ch; (ch=fgetc(in)) != EOF; fputc(ch,out));
	
	fclose(in);
	fclose(out);
}
