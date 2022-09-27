#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	puts("Substitution Cipher");
	label:
	puts("(26 alphabet characters, not repeat)");
	printf("\t*Input key? : ");
	char key[27];		gets(key);
	
    // check for the length of key
    if (strlen(key) != 26)
    {
        puts("Key must contain 26 characters.");
        goto label;
    }
    // check if key is alphabatic or not
    for (int i=0; key[i]!='\0'; i++)
    {
        if (!(isalpha(key[i])))
        {
            puts("Key must contain alphabetical characters only.");
            goto label;
        }
        // check for the repetition of characters using nested +1 loop
        for(int j=i+1; key[j]!='\0'; j++)
        {
            // convert letters to upper case to check
            if(toupper(key[i]) == toupper(key[j]))
            {
                puts("Key characters must not repeat.");
                goto label;
            }
        }
    }
    
    puts(key);
    
    // prompt for the user input
    printf("\t\t**Enter Message: ");
    char str[100];		gets(str);
    // traversing the user input
    for(int i=0; str[i]!='\0'; i++)
    {
        if (isalpha(str[i]))
        {
            int index;
            // if the char is upper case get the index
            if (isupper(str[i]))
            {
                index = str[i] - 'A';
                str[i] = toupper(key[index]);
            }
            // if the char is lower case get the index
            else
            {
                index = str[i] - 'a';
                str[i] = tolower(key[index]);
            }
        }
    }
    // output
    printf("*Ciphertext: %s\n", str);
}
