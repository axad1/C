#include<stdio.h>
#include<cs50.c>
// TODO: REMEMBER TO CHANGE THE HEADER TO .h
int main()
{
	int height;
	do
	{
		height = get_int("Enter height: ");
	}
	while(height<1 || height>8);
//	rows
	for(int i=0;i<height;i++)
	{
//		spaces
		for(int s=height-i;s>1;s--)
		{
			printf(".");
		}
//		first half
		for(int j=0;j<=i;j++)
		{
			printf("#");
		}
//		blank spaces
		printf("  ");
//		second half
		for(int k=0;k<=i;k++)
		{
			printf("#");
		}
//		new line
		printf("\n");
	}
}
