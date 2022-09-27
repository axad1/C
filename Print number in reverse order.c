// print number in reverse order
#include<stdio.h>
int main()
{
	short num,a,b;
	printf("Enter 3 digit number : ");
	scanf("%d",&num);
	
	a=num/100;
	num=num%100;
	b=num/10;
	num=num%10;
	
	printf("\n---output---\n");
	printf("Number in reverse order = %d%d%d",num,b,a);
}
