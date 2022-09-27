#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	
	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numbers[] = "0123456789";
	char symbols[] = "!@#$%^&*()";
	
	char password[6];
	
	for(int i=0; i<5; i++)
	{
		int n = rand() % 4;
		
		if(n==1)
		
			password[i] = upper[rand()%26];
		else if(n==2)
			password[i] = lower[rand()%26];
		else if(n==3)
			password[i] = numbers[rand()%10];
		else
			password[i] = symbols[rand()%10];
	}
	
	puts(password);
}
