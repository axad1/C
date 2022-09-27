#include<stdio.h>
int main()
{
/*
	5*2 = 10
	10*2 = 20
	20*2 = 40....
*/
	for(int i=0; i<5; i++)
		printf("%d\n", 5<<i);
}
