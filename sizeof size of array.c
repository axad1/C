//	sizeof() cannot work in dynamic arrays or functions
//	best idea is to use constants or hardcode or pass an additional size parameter
#include<stdio.h>
#define SIZE(a) sizeof(a)/sizeof(a[0])
int main()
{
	//	use constant
	const int size = 2;
	
	//	here initialization cannot be made like this
	//	int a[size] = values; xxx
	
	int a[size];
	
	printf("%d", SIZE(a));
}
