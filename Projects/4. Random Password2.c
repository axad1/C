#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	// 72 char
	char data[72] = "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789" "!@#$%^&*()";
	
	char password[6];
	
	for(int i=0; i<5; i++)
	{
		password[i] = data[rand() % 72];
	}
	puts(password);
}
