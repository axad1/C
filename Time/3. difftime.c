#include<stdio.h>
#include<time.h>
int main()
{
	time_t start = time(NULL), end;
	
	getchar();
	
	time(&end);
	
	printf("Time taken: %f", difftime(end,start));
	
}
