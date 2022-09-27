#include<stdio.h>
int main()
{
	FILE *out = fopen("asad.txt", "w");
	char str[] = "This is cs50.";
	
	fwrite(str,sizeof(str),1,out);
}
