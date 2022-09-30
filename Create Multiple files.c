#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *file;
	//	create 1-9 files
	char s[6] = "1.txt";
	for(int i=0; i<10; i++)
	{
		file = fopen(s, "w");
		fclose(file);
		s[0]++;
	}
	
	//	create 10-99 files
	char s2[7] = "10.txt";
	for(int i=0; i<90; i++)
	{
		file = fopen(s2, "w");
		fclose(file);
		s2[1]++;
		if(s2[1]>'9')
		{
			s2[0]++;
			s2[1]='0';
		}
	}
	
}
