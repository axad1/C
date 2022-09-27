#include<stdio.h>
#include<stdlib.h>	//rand()
#include<time.h>	//time()
int main()
{
	srand(time(NULL));
	int n = rand() % 10 + 1;
	for(int i=5; i>0; i--)
	{
		int x;
		printf("Guess a number (1 to 10)\t%d): ", i);
		scanf("%d", &x);
		
		if(x<1 || x>10)
		{
			printf("Not in range\n");
			return 0;
		}
		if(x==n)
		{
			printf("\tYou got it!");
			return 0;
		}
		else if(x>n)
			printf("\tToo higher\n");
		else
			printf("\tToo lower\n");
	}
	printf("Better luck next time\n");
	printf("Answer = %d", n);
}
