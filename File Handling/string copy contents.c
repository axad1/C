#include<stdio.h>
int main()
{
	FILE *in, *out;
	in = fopen("text.txt","r");
	out = fopen("asad.txt","w");
	if(!in || !out)
	{
		printf("Errorr");
		return 1;
	}
	char str[10];
	while(fgets(str,10,in) != NULL)
	{
		fputs(str,out);
	}
	fclose(in);
	fclose(out);
}
