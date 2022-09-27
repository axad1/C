//	rename
#include<stdio.h>
int main()
{
	//	int rename (const char *oldname, const char *newname);
	int value = rename("temp.dat", "temp.txt");
	if (value == 0)
		puts("File renamed successfully");
	else
		perror("Unable to rename file");
}
