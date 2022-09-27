#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int validate(char *str);
int main()
{
	puts("Vigenere Cipher");
	//	input key
	puts("(alphabetical characters)");
	printf("\t*Input key? : ");
	char key[30];		gets(key);
	//	validate key
	int keysize = validate(key);
	
	//	input str
	printf("Enter Message: ");
	char str[100];		gets(str);
	//	validate str
	int strsize = validate(str);
	
	//	generate key of str's equal length
	printf("\nkey =\t");
	for(int i=0; i<strsize; i++)
		printf("%c\t", key[i%keysize]);
	//	print numeric value of key
	printf("\nkey =\t");
	for(int i=0; i<strsize; i++)
		printf("%d\t", key[i%keysize] - 'A');
	
	
	//	print str
	printf("\n\nstring =\t");
	for(int i=0; i<strsize; i++)
		printf("%c\t", str[i]);
	//	print str numeric values
	printf("\nstring =\t");
	for(int i=0; i<strsize; i++)
		printf("%d\t", str[i]);
	
	
	//	Encrypt	
	printf("\n\nEnctypt =\t");
	for(int i=0; i<strsize; i++)
	{
		str[i] = ((str[i] + key[i%keysize]) % 26) + 'A';
		printf("%c\t", str[i]);
	}
	//	print numeric values
	printf("\nEncrypt =\t");
	for(int i=0; i<strsize; i++)
		printf("%d\t", str[i]);
	
	//	Cipher
	printf("\n\nCipher: %s\n", str);
	
	//	print table
	puts("");
	for(char c='A'; c<='Z'; c++)
	{
		printf("%c | %d\n", c, c-'A');
	}
}

int validate(char *str)
{
	int count = 0;
	for(int i=0; str[i]!='\0'; i++)
	{
		if(isdigit(str[i]))
		{
			puts("Input alphabetical characters only.");
			exit(0);
		}
		if(!isspace(str[i]))
		{
			if(islower(str[i]))
			{
				str[i] = toupper(str[i]);
			}
			str[count++] = str[i];
		}
	}
	str[count] = '\0';
	return count;
}
