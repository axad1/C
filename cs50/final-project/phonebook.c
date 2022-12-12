#include "helper.c"
//#include <sys/stat.h>
//#include <io.h>  //	to use mkdir("data");
void Login()
{
    FILE *in = fopen("users.dat", "r");
    if (!in)
    {
        puts("\t\t** No user is registered. (Kindly register a user first)");
        return;
    }

    char name[SIZE], pass[SIZE], tname[SIZE], tpass[SIZE];

    printf("\t\t** Enter username: ");
    fgets(name, SIZE, stdin);
    if (!validate(name))
    {
        return;
    }

    printf("\t\t** Enter password: ");
    fgets(pass, SIZE, stdin);
    if (!validate(pass))
    {
        return;
    }

    int found = 0;
    while (!feof(in))
    {
        fgets(tname, SIZE, in);
        fgets(tpass, SIZE, in);

        if (strcmp(name, tname) == 0)
        {
            found = 1;
            if (strcmp(pass, tpass) == 0)
            {
                tname[strlen(tname) - 1] = '\0';
                //	for linux
                //	mkdir("data", 0777);
                //	for windows
				//	mkdir("data");
                //	char loc[50] = "data/";
                //	sscanf(strcat(loc, strcat(tname, ".dat")), "%s", FILENAME);
                sscanf(strcat(tname, ".dat"), "%s", FILENAME);
                menu();
            }
            else
            {
                puts("\t\t\t--- Password incorrect ---");
            }
            break;
        }
    }

    fclose(in);
    if (!found)
    {
        puts("\t\t\t--- User not found ---");
    }
}

void Register()
{
    char name[SIZE], pass[SIZE], tname[SIZE], tpass[SIZE];
    FILE *file = fopen("users.dat", "a+");
    if (!file)
    {
        puts("File Error");
        return;
    }
    printf("\t\t** Enter username: ");
    fgets(name, SIZE, stdin);
    if (!validate(name))
    {
        return;
    }

    while (1)
    {
        fgets(tname, SIZE, file);
        if (feof(file))
        {
            break;
        }
        fgets(tpass, SIZE, file);

        if (strcmp(name, tname) == 0)
        {
            puts("\t\t\t*** Username already exists");
            fclose(file);
            return;
        }
    }

    printf("\t\t** Enter password: ");
    fgets(pass, SIZE, stdin);
    if (!validate(pass))
    {
        return;
    }

    fprintf(file, "%s%s", name, pass);
    puts("\t\t\t*** Register successfully");

    fclose(file);
}

int main()
{
    while (1)
    {
        printf("\n***** Phonebook *****\n1. Login\n2. Register\n0. Exit\n\t* Select: ");
        char c = getchar();
        if(c == '\n')
		{
			goto invalid;
		}
        char extra[SIZE];
        fgets(extra, SIZE, stdin);
        if (extra[0] != '\n')
        {
            goto invalid;
        }
        switch(c)
		{
			case '1':
				Login();
					continue;
			case '2':
				Register();
					continue;
			case '0':
				return(0);
		}
        invalid:
            puts("\t\t--- Invalid input ---");
            continue;
    }
}

