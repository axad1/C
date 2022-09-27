#include <cs50.c>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check for the count of program
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check for the length of key
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check if key is alphabatic or not
    else
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            // check if not an alphabet
            if (!(isalpha(argv[1][i])))
            {
                printf("Key must contain alphabetical characters only.\n");
                return 1;
            }
            // check for the repetition of characters using nested +1 loop
            for (int j = i + 1; argv[1][j] != '\0'; j++)
            {
                // convert letters to upper case to check
                if (toupper(argv[1][i]) == toupper(argv[1][j]))
                {
                    printf("Key characters must not repeat.\n");
                    return 1;
                }
            }
        }
    }
    // prompt for the user input
    string str = get_string("","Enter plaintext: ");
    // traversing the user input
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            int index;
            // if the char is upper case get the index
            if (isupper(str[i]))
            {
                index = str[i] - 'A';
                str[i] = toupper(argv[1][index]);
            }
            // if the char is lower case get the index
            else
            {
                index = str[i] - 'a';
                str[i] = tolower(argv[1][index]);
            }
        }
    }
    // output
    printf("ciphertext: %s\n", str);
}
