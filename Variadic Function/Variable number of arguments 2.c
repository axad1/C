#include<stdio.h>
#include<stdarg.h>
#include<string.h>
void print(char *placeholder, ...)
{
	int num_args = strlen(placeholder);
	
	va_list args;
	
	va_start(args, placeholder);
	
	for(int i=0; i<num_args; i++)
	{
		if(placeholder[i] == 'd')
		{
			int x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if(placeholder[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
	}
}

int main()
{
	print("f", 1.1);
}
