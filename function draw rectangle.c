#include<stdio.h>
void draw_H()
{
	int i=0;
	while(i<=21)
	{
		printf("*");
		i++;
	}
	printf("\n");
}
void draw_V()
{
	int i=0;
	while(i<5)
	{
		printf("*                    *\n");
		i++;
	}
}
int main()
{
	draw_H();
	draw_V();
	draw_H();
}
