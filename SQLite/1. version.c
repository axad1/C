#include<stdio.h>
#include<sqlite3.c>
int main()
{
	//	sqlite_libversion()
	printf("%s\n", sqlite3_libversion());
}
