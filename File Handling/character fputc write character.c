#include<stdio.h>
#include<conio.h>
int main(void)
{
	FILE *out;
	char ch;
	out = fopen("text.txt","w");
	if(!out)
	{
		printf("Erorr");
		return 1;
	}
	printf("Enter a character (. to end): ");
	while(ch != '.')
	{
//		ch = getche();
//		scanf("%c", &ch);
		ch = getchar();
		fputc(ch,out);	
	}
	fclose(out);
	return 0;
}
