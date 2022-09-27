#include<stdio.h>
void hey()
{
	printf("hello, world\n");
}
void hey2(char *s)
{
	printf("hello, %s\n", s);
}

int main()
{
	void (*f)() = hey;
	(*f)();
	
	void (*f2)(char*);
	f2 = &hey2;
	(*f2)("Asad");
	
	
}
