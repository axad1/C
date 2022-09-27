#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[5] = "AbcDe";
	/*
	isalpha(char);
	ctype.h library
	check wether the input is aplhabet or not
	a-z || A-Z
	return 0 if not alphabet
	return 1 character is Uppercase
	return 2 character is Lowercase
	*/
	
	for(int i=0;i<5;i++)
	printf("%i",isalpha(s[i]));
	
	
}
