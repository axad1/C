#include<stdio.h>
#include<time.h>
int main()
{
	time_t t = time(0);
	
	struct tm *tm = localtime(&t);
	
	char buffer[30];
	
	/*
	strftime() function stores the
	current time as Hours : Minutes
	%I %M and %p-> format specifier
	*/
	strftime(buffer, sizeof(buffer), "%I:%M:%S %p", tm);
	
	puts(buffer);
	
}
