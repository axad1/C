#include<stdio.h>
#include<time.h>
int main()
{
	time_t t = time(NULL);
	
	//	struct tm* localtime(const time_t*)
	struct tm *tm = localtime(&t);
	
	//	char* asctime(struct tm*)
	printf("%s", asctime(tm));
}
