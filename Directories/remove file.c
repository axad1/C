#include<stdio.h>
int main()
{
	int value = remove("temp.dat");
	if (value == 0)
		puts("File erased from disk");
	else
		perror("Unable to erase file");
}
