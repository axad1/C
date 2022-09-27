#include<stdio.h>
struct test{
	int n;
	char c;
};
int main()
{
	test obj;
	obj.c = 'c';
	obj.n = 10;
	printf("%d\n%c",obj.n,obj.c);
}
