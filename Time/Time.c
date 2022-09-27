#include<stdio.h>
#include<time.h>
int main()
{
//	Seconds since January 1, 1970
	
	//	time_t is long long
	time_t t;
	
/*	time_t time(time_t *second)
	pointer parameter accepts the address of variable &t
	also return time_t
*/
	time(&t);
	
	printf("%ld", t);
}
