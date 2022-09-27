#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<ctype.h>
#define SIZE 30
char FILENAME[SIZE];
void menu();
void add();
void show();
void searchname();
void searchnumber();
void delcontact();
void deleteall();
int validate(char *str)
{
    return str[0]=='\n' ? puts("\t\t\t--- Invalid input ---"), 0 : 1;
}

void menu()
{
    while(1)
	{
		puts("\n----- Welcome -----");
		puts("1) Add new record");
		puts("2) Display all records");
		puts("3) Search by name");
		puts("4) Search by number");
		puts("5) Delete contact");
		puts("6) Delete all contacts");
		puts("0) Logout");
		printf("\t* Select: ");

		char extra[SIZE];
		char c = getchar();
		if(c == '\n')
			goto invalid;

		fgets(extra, SIZE, stdin);
		if(extra[0] != '\n')
			goto invalid;
		puts("");

        switch(c)
		{
			case '1':
				add();
					continue;
			case '2':
				show();
					continue;
			case '3':
				searchname();
					continue;
			case '4':
				searchnumber();
					continue;
			case '5':
				delcontact();
					continue;
			case '6':
				deleteall();
					continue;
			case '0':
				return;
		}
		invalid:
			puts("\t\t--- Invalid input ---");
			continue;
	}
}

//	add new contact
void add()
{
    char name[SIZE], num[SIZE];

    printf("\t\t** Enter name: ");
    fgets(name, SIZE, stdin);
    if(!validate(name))
    {
        return;
    }

    printf("\t\t** Enter number: ");
    fgets(num, SIZE, stdin);
    if(!validate(num))
    {
        return;
    }

    FILE *out;
    out = fopen(FILENAME, "a");

    fprintf(out, "%s%s", name, num);
    fclose(out);
    puts("\t\t\t*** Contact saved successfully");
}

//	show all contacts
void show()
{
    FILE *in = fopen(FILENAME, "r");
    if(!in)
    {
        puts("\t\t** File error");
        return;
    }
    char name[SIZE], num[SIZE];
    int count = 0;
    while(1)
    {
        fgets(name, SIZE, in);
        if(feof(in))
        {
            break;
        }
        fgets(num, SIZE, in);

        printf("\t\t=> %s\t\t   %s\n", name, num);
        count++;
    }
    if(count == 0)
    {
        puts("\t\t** No contacts");
    }
    else
    {
        printf("\t* Contacts = %d *\n", count);
    }
    fclose(in);
}

//	search by name
void searchname()
{
    FILE *in = fopen(FILENAME, "r");
    if(!in)
    {
        puts("\t\t** File error");
        return;
    }

    //	get name to search
    char name[SIZE], num[SIZE], tname[SIZE];
    printf("\t\t** Enter name to search: ");
    fgets(name, SIZE, stdin);
    if(!validate(name))
        return;

    //	check name
    int found = 0;
    while(1)
    {
        //	get name
        fgets(tname, SIZE, in);
        //	check end of file
        if(feof(in))
            break;
        //	get number
        fgets(num, SIZE, in);

        //	compare
        if(strcasecmp(name, tname) == 0)
        {
            found = 1;
            printf("\t\t\t=> %s\t\t\t   %s\n", tname, num);
        }
    }
    if(!found)
        puts("\t\t\t*** Not found");
    fclose(in);
}

//	search by number
void searchnumber()
{
    FILE *in = fopen(FILENAME, "r");
    if(!in)
    {
        puts("\t\t** File Error");
        return;
    }

    char name[SIZE], num[SIZE], tnum[SIZE];
    //	get number to search
    printf("\t\t**Enter number: ");
    fgets(num, SIZE, stdin);
    if(!validate(num))
        return;

    //	check number
    int found = 0;
    while(1)
    {
        //	get name
        fgets(name, SIZE, in);
        if(feof(in))
            break;
        //	get number
        fgets(tnum, SIZE, in);

        //	compare
        if(strcasecmp(num, tnum) == 0)
        {
            found = 1;
            printf("\t\t\t=> %s\t\t\t   %s\n", name, num);
        }
    }
    if(!found)
        puts("\t\t\t\t*** Not found");
    fclose(in);
}

//	delete contact
void delcontact()
{
    FILE *in = fopen(FILENAME, "r");
    if(!in)
    {
        puts("\t\t** File error");
        return;
    }
    //	get name to delete
    char name[SIZE], tname[SIZE], num[SIZE];
    printf("\t\t**Enter contact name to delete: ");
    fgets(name, SIZE, stdin);
    if(!validate(name))
        return;

    //	save starting position
    fpos_t pos;
    fgetpos(in, &pos);

    //	find the position no. of contact.
    int found=0,contact=0;
    while(1)
    {
        //	get name
        fgets(tname, SIZE, in);
        //	remove newline from the end of name
        //	name[strlen(name) - 1] = '\0';
        //	check end of file
        if(feof(in))
            break;
        //	get number
        fgets(num, SIZE, in);
        contact++;

        //	compare
        if(strcasecmp(name, tname) == 0)
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
        fgets(tname, SIZE, in);
        fgets(num, SIZE, in);
        fprintf(out,"%s%s", tname, num);
    }
    //	skip the contact to delete
    fgets(tname, SIZE, in);
    fgets(num, SIZE, in);
    //	copy remaining half
    for(char ch; (ch=fgetc(in)) != EOF; fputc(ch,out));

    fclose(in);
    fclose(out);
    name[strlen(name)-1] = '\0';
    printf("\t\t\t*** %s deleted successfully\n", name);

    remove(FILENAME);
    rename("temp.txt", FILENAME);
}

//	delete all
void deleteall()
{
    printf("\t\t** Are you sure? (Y/N): ");
    char c = tolower(getchar());
    if(c == '\n')
    {
        puts("\t\t\t--- Invalid input ---");
        return;
    }
    char extra[SIZE];
    fgets(extra, SIZE, stdin);
    if(c == 'y')
    {
        FILE *out = fopen(FILENAME, "w");
        fclose(out);
        puts("\t\t\t*** Deleted");
    }
    else
        puts("\t\t\t*** Cancelled");
}
