#include<stdio.h>
int main()
{
/*	Bitwise compliment operator is an unary operator (works on only one operand).
	It changes 1 to 0 and 0 to 1.
	Computer store negative numbers as 2's complement
	2 in binary is 		0000 0010
	1's complement is	1111 1101	due to LSB 1 computer treat this as negative number
	to know what negative number it is we have to take 2's complement
	2's complement is	0000 0101	and add negative sign
	this is -3
*/
    int a = 2;
    printf("Complement Operation = %i", ~a);
}
