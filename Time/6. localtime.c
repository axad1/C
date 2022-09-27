#include<stdio.h>
#include<time.h>
int main()
{
	time_t t = time(0);
	printf("%ld\n", t);
	
	//	convert time_t to struct tm
	struct tm *tm = localtime(&t);
	puts(asctime(tm));
	
	//	convert struct tm to time_t
	time_t t2 = mktime(tm);
	printf("%ld", t2);
	
}
