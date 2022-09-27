#include<stdio.h>
int main()
{
//	input with space in C using scanf()
	char str[20];
	scanf("%[^\n]*%c", str);
	
/*	Here, [] is the scanset character.
	^\n tells to take input until newline doesn’t get encountered.
	Then, with this %*c, it reads newline character
	and here used * indicates that this newline character is discarded.
*/
	puts(str);
}
