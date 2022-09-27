#include<stdio.h>
#include<limits.h>
int main()
{
//	int
	printf("int max:\t%i\n", INT_MAX);
	printf("int min:\t%i\n", INT_MIN);
	//	%u for unsigned integer
	printf("unsigned int max:\t%u\n", UINT_MAX);
	
	printf("\n");
//	short
	//	%hi for signed short
	printf("short max:\t%hi\n", SHRT_MAX);
	printf("short min:\t%hi\n", SHRT_MIN);
	//	%hu for unsigned short
	printf("unsigned short max:\t%hu\n", USHRT_MAX);
	
	printf("\n");
//	long
	printf("long max:\t%li\n", LONG_MAX);
	printf("long min:\t%ld\n", LONG_MIN);
	printf("unsigned long max:\t%lu\n", ULONG_MAX);
	
	printf("\n");
//	long long
	printf("long long max:\t%lli\n", LLONG_MAX);
	printf("long long min:\t%lld\n", LLONG_MIN);
	printf("unsigned long long max:\t%llu\n", ULLONG_MAX);
}
