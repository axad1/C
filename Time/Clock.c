#include<stdio.h>
#include<time.h>
int main()
{
/*
	“time.h”	clock()
	returns the number of clock ticks elapsed since the program was launched
	clock_t clock(void);	clock_t is long
	return value of CPU time as clock_t
	on error -1 is returned
	To get the number of seconds used, divide by CLOCKS_PER_SEC
	where CLOCKS_PER_SEC is 1000000 on typical 32 bit system
*/
	clock_t start = clock();
	printf("start = %ld\n", start);
	
	for(int i=0; i<5000; i++)
	printf("%n");
	
	clock_t end = clock();
	printf("\nend = %ld\n", end);
	
	float taken = (end-start) / (float)CLOCKS_PER_SEC;
	printf("Time taken by seconds = %f", taken);
	
	printf("\nclocks per second = %d", CLOCKS_PER_SEC);
}
