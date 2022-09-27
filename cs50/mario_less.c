#include<stdio.h>
#include<cs50.c>
// TODO: REMEMBER TO CHANGE THE HEADER TO .h
int main()
{
	int height;
	do
	{
		height = get_int("Enter Height: ");
	}while(height < 1 || height > 8);
	
	for (int i = 0; i < height; i++)
	{
//		spaces
		for(int s = height-1; s > i; s--)
		{
			printf(" ");
		}
//		hashes
		for (int j = 0; j <= i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}
