#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30
void Login()
{
	FILE *in = fopen("users.txt", "r");
	if(!in)
	{
		puts("File Error");
		return;
	}
	
	char name[SIZE], pass[SIZE], tname[SIZE],tpass[SIZE];
	printf("Enter username: ");
	fgets(name, SIZE, stdin);
	printf("Enter password: ");
	fgets(pass, SIZE, stdin);
	
	int found = 0;
	while(1)
	{
		if(feof(in))
			break;
		fgets(tname, SIZE, in);
		fgets(tpass, SIZE, in);
		
		//	no need to remove newline from the end of name
		//	tname[strlen(tname) - 1] = '\0';
		
		if(strcmp(name,tname) == 0)
		{
			found = 1;
			//	no need to remove newline from the end of name
			//	tpass[strlen(tpass) - 1] = '\0';
			if(strcmp(pass,tpass) == 0)
				puts("\tWelcome!");
			else
				puts("\tpassword incorrect");
			break;
		}
	}
	
	fclose(in);
	if(!found)
		puts("\tFalse Login");
}

void Register()
{
	char name[SIZE], pass[SIZE], tname[SIZE], tpass[SIZE];
	FILE *file = fopen("users.txt", "a+");
	if(!file)
	{
		puts("File Error");
		return;
	}
	printf("Enter username: ");
	fgets(name, SIZE, stdin);
	
	while(1)
	{
		fgets(tname, SIZE, file);
		if(feof(file))
			break;
		fgets(tpass, SIZE, file);
		puts(name);
		puts(tname);
		
		//	no need to remove newline from the end of name
		//	tname[strlen(tname) - 1] = '\0';
		
		if(strcmp(name,tname) == 0)
		{
			puts("\tUsername already exists");
			fclose(file);
			return;
		}
	}
	
	printf("Enter password: ");
	fgets(pass, SIZE, stdin);
	
	fprintf(file, "%s%s", name, pass);
	puts("\tRegister successfully");
	
	fclose(file);
}

int main()
{
	while(1)
	{
		char extra[SIZE*2];
		printf("----------\n1. Login\n2. Register\n3. Exit\nSelect: ");
		char c = getchar();
//		fscanf(stdin, "%c" , &c);
		fgets(extra, SIZE*2, stdin);
		if(c == '1')
			Login();
		else if(c == '2')
			Register();
		else if(c == '3')
			break;
		else
			puts("\tInvalid input");
		system("pause");
		system("cls");
	}
}
