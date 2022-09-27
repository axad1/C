#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void menu();
void add();
void show();
void searchname();
void searchnumber();
void delcontact();
void deleteall();

int main()
{
	while(1)
	{
		menu();
		system("pause");
		system("cls");
	}
}

void menu()
{
	puts("*****PhoneBook*****");
	puts("1) Add new record");
	puts("2) Display all records");
	puts("3) Search by name");
	puts("4) Search by number");
	puts("5) Delete contact");
	puts("6) Delete all contacts");
	puts("0) Exit");
	printf("\t* Select: ");
	char choice = getche();
	puts("");
	switch(choice){
		case '1':
			add();
				break;
		case '2':
			show();
				break;
		case '3':
			searchname();
				break;
		case '4':
			searchnumber();
				break;
		case '5':
			delcontact();
				break;
		case '6':
			deleteall();
				break;
		case '0':
			exit(0);
				break;
		default:
			puts("\t* Invalid choice");
			break;
		}
}

//	add new contact
void add()
{
	char name[30], number[20];
	printf("\t\t** Enter name: ");
	gets(name);
	printf("\t\t** Enter number: ");
	gets(number);
	
	FILE *out;
	out = fopen("data.txt", "a");
	
	fprintf(out,"%s\n%s\n", name, number);
	fclose(out);
	puts("\t\t\t*** Contact saved successfully");
}

//	show all contacts
void show()
{
	FILE *in = fopen("data.txt", "r");
	if(!in)
	{
		puts("\t\t** File error");
		return;
	}
	char name[30], number[30];
	int count = 0;
	while(1)
	{	
		fgets(name, 30, in);
		if(feof(in))
			break;
		fgets(number, 30, in);
		fputs(name, stdout);
		fputs(number, stdout);
		printf("\n");
		count++;
	}
	if(count == 0)
	puts("\t\t** No contacts");
	else
	printf("\t* Contacts = %i\n", count);
	fclose(in);
}

//	search by name
void searchname()
{
	FILE *in = fopen("data.txt", "r");
	if(!in)
	{
		puts("\t\t** File error");
		return;
	}
	//	get name to search
	char name[30], number[30], nm[30];
	printf("\t\t** Enter name to search: ");
	gets(nm);
	
	//	check name
	int found = 0;
	while(1)
	{	
		//	get name
		fgets(name, 30, in);
		//	check end of file
		if(feof(in))
			break;
		//	remove newline from the end of name
		name[strlen(name) - 1] = '\0';
		//	get number
		fgets(number, 30, in);
		//	compare
		if(stricmp(name, nm) == 0)
		{
			found = 1;
			printf("\t\t\t*** %s\n", number);
			break;
		}
	}
	if(!found)
	puts("\t\t\t\t*** Not found");
	fclose(in);
}

//	search by number
void searchnumber()
{
	FILE *in = fopen("data.txt", "r");
	if(!in)
	{
		puts("\t\t** File error");
		return;
	}
	//	get number to search
	char name[30], number[30], no[30];
	printf("\t\t**Enter number: ");
	gets(no);
	//	check number
	int found = 0;
	while(1)
	{	
		//	get name
		fgets(name, 30, in);
		//	check end of file
		if(feof(in))
			break;
		//	get number
		fgets(number, 30, in);
		//	remove newline from the end of number
		number[strlen(number) - 1] = '\0';
		//	compare
		if(stricmp(number, no) == 0)
		{
			found = 1;
			printf("\t\t\t*** %s\n", name);
			break;
		}
	}
	if(!found)
		puts("\t\t\t\t*** Not found");
	fclose(in);
}

//	delete contact
void delcontact()
{
	FILE *in = fopen("data.txt", "r");
	if(!in)
	{
		puts("\t\t** File error");
		return;
	}
	//	get name to delete
	char name[30], number[30], nm[30];
	printf("\t\t**Enter contact name to delete: ");
	gets(nm);
	
	//	save starting position
	fpos_t pos;
	fgetpos(in, &pos);
	
	//	find the position no. of contact.
	int found=0,contact=0;
	while(1)
	{	
		//	get name
		fgets(name, 30, in);
		//	remove newline from the end of name
		name[strlen(name) - 1] = '\0';
		//	check end of file
		if(feof(in))
			break;
		//	get number
		fgets(number, 30, in);
		contact++;
		//	compare
		if(stricmp(name, nm) == 0)
		{
			found = 1;
			break;
		}
	}
	if(!found)
	{                          
		puts("\t\t\t*** Not found");
		return;
	}
	
	//	set position to start of file
	fsetpos(in, &pos);
	
	FILE *out = fopen("temp.txt", "w");
	//	copy first half
	for(int i=1; i<contact; i++)
	{
		fgets(name, 30, in);
		fgets(number, 30, in);
		fprintf(out,"%s%s", name, number);
	}
	//	skip the contact to delete
	fgets(name, 30, in);
	fgets(number, 30, in);
	//	copy remaining half
	for(char ch; (ch=fgetc(in)) != EOF; fputc(ch,out));
	
	fclose(in);
	fclose(out);
	printf("\t\t\t*** %s deleted successfully\n", name);
	
	remove("data.txt");
	rename("temp.txt", "data.txt");
}

//	delete all
void deleteall()
{
	printf("\t\t** Are you sure? (Y/N): ");
	char c = tolower(getche());
	puts("");
	if(c == 'y')
	{
		FILE *out = fopen("data.txt", "w");
		fclose(out);
		puts("\t\t\t*** Deleted");
	}
	else
		puts("\t\t\t*** Cancelled");
}
