#include<stdio.h>
int main()
{
	FILE *in = fopen("text.txt","r");
	if(!in)
	{
		printf("Errorr");
		return 1;
	}
	char str[25];
//	while(fgets(str,25,in) != NULL)
	while(fgets(str,25,in))
	printf("%s",str);
	fclose(in);
}
