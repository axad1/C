#include <cs50.c>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for the count argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // check for the numeric key
    else
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (isalpha(argv[1][i]) != 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    // get key
    int key = atoi(argv[1]);

    printf("\nkey = %i\n", key);

    // get plain text
    string str = get_string("","Enter plain text: ");

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
    printf("ciphertext: %s\n", str);
    return 0;
}
