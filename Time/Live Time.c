#include<stdio.h>
#include<time.h>
#include<unistd.h>
int main()
{
	while(1)
	{
		time_t t = time(0);
		struct tm *tm = localtime(&t);
		char c[30];
		strftime(c,30,"%I:%M:%S%p", tm);
		puts(c);
		sleep(1);
	}
}
