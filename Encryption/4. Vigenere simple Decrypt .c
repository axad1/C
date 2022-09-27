#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int validate(char *str);
int main()
{
	puts("Vigenere Cipher Decrypt");
	//	input key
	puts("(alphabetical characters)");
	printf("\t*Input key? : ");
	char key[30];		gets(key);
	//	validate key
	int keysize = validate(key);
	
	//	input str
	printf("Enter Cipher: ");
	char str[100];		gets(str);
	//	validate str
	int strsize = validate(str);
	
	//	make key of length str in a cyclic manner
	if(keysize<strsize)
	{
		int i=0;
		while(keysize<strsize)
			key[keysize++] = key[i++];
		key[keysize] = '\0';
	}
	
	//	Decrypt
	for(int i=0; i<strsize; i++)
		str[i] = (((str[i]-key[i]) + 26) % 26) + 'A';
		
	printf("*Message: %s", str);
}
//	ends

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
