#include <stdio.h>
#include <ctype.h>
int main()
{
	puts("Caesar Cipher");
	label:
	printf("Numeric key? : ");
	//	k[1] can input 4 digits
    char k[1];		gets(k);
	
	// check for the numeric key
    for (int i = 0; k[i] != '\0'; i++)
    {
        if (isdigit(k[i]) == 0)
        {
            puts("\t*Key must be numeric");
            goto label;
        }
    }

    // convert key to numeric
    int key;	sscanf(k,"%d",&key);
    
    // get message
    printf("\t*Enter Message: ");
    char str[100];	fgets(str,sizeof(str),stdin);
	
//	TODO: key = 0 case
	
    // caesar cipher
    for (int i = 0; str[i] != '\0'; i++)
    {
        // check isalpha for uppercase
        if (isalpha(str[i]))
        {
            {
                if (isupper(str[i]))
                {
                    str[i] = (((str[i] - 'A') + key) % 26) + 'A';
                }
                else
                {
                    str[i] = ((str[i] - 'a' + key) % 26) + 'a';
                }
            }
        }
    }
    printf("*Cipher: %s", str);
}
