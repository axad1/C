#include<stdio.h>
#include<errno.h>
int main()
{
	sscanf("Error_Occurs", "%s", stderr);
	printf("%s", stderr);
}
