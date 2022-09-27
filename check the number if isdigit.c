#include<stdio.h>
#include<ctype.h>
int main()
{
//  isdigit - check whether a character is a digit
//  returns a non-zero int if c is a decimal digit and 0 if c is not a decimal digit

	char c;
	printf("Enter a char: ");
	scanf("%c",&c);
	
//	check if it is number or not
	if(isdigit(c))
		printf("yes");
	else
		printf("no");
		
    return 0;
}
