#include<stdio.h>
int main()
{
	char s[] = "12345";
	int n,m;
	
	/*
	using atoi() function
	stdlib.h libraray
	returns integer
	*/
	n = atoi(s);

	/*
	using sscanf() function
	it reads from a string
	stdio.h library
	*/
	sscanf(s,"%d",&m);
	
	printf("%i\n",n);
	printf("%i\n",m);
}
