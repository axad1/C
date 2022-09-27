#include<stdio.h>
int get_length1(int n)
{
	int length =  ( n==0 ) ? 1 : (int)log10(n)+1;
	return length;
}

int get_length2(int n)
{
	int length = 0;
	do
	{
    	++length;
    	n = n / 10;
	}while(n);
	return length;
}

int get_length3(int n)
{
	int length=1;
	while (n>=10)
	{
    	n/=10;
    	length++;
	}
	return length;
}

int get_length4(int n)
{
	int length=0;
	while (n>0)
	{
    	n/=10;
    	length++;
	}
	return length;
}

int main(void)
{
	int x;
	printf("Enter number : ");
	scanf("%i",&x);
	
	int length = get_length4(x);

	printf("Length = %i",length);
}
