#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	char username[20], password[20], un[20], pw[20];
	int found;
	while(1)
	{
		printf("----------\n1. Login\n2. Register\n3. Exit\nSelect: ");
		char choice = getche();
		printf("\n");
		switch(choice)
		{
			case '1':{
				FILE *in = fopen("data.txt", "r");
				if(!in)
				{
					printf("File Error\n");
					return 0;
				}
				printf("Enter username: ");
				gets(username);
				printf("Enter password: ");
				gets(password);
				found = 0;
				while(fscanf(in, "%s%s", un, pw) != EOF)
				{
					if(strcmp(username, un) == 0)
					{
						found = 1;
						if(strcmp(password, pw) == 0)
						printf("\tWelcome %s!\n", username);
						else
						printf("\tpassword incorrect\n");

						fclose(in);
						break;
					}
				}
				fclose(in);
				if(found == 0)
				printf("\tFalse Login!\n");
			break;
			}
			
			case '2':{
				FILE *out = fopen("data.txt", "a+");
				if(!out)
				{
					printf("\tFile Error\n");
					return 0;
				}
				
				printf("Enter username: ");
				gets(username);
				found = 0;
				while(fscanf(out, "%s%s", un, pw) != EOF)
				{
					if(strcmp(username, un) == 0)
					{
						found = 1;
						printf("\tUser already exist\n");
						fclose(out);
						break;
					}
				}
				if(found == 1)
				break;
				
				printf("Enter password: ");
				gets(password);
				fprintf(out, "%s\n%s\n", username, password);
				fclose(out);
				printf("\tRegister Successfully!\n");
			break;
			}
			
			case '3':
			return 0;
			
			default:
			printf("\twrong input\n");
			break;
		}
		system("pause");
		system("cls");
	}
}
