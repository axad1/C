#include<stdio.h>
#include<time.h>
int main()
{
	time_t t = time(NULL);
	
	//	UTC (Coordinated Universal Time) of the system
	struct tm *tm = gmtime(&t);
	
	puts(asctime(tm));

}
