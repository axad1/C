#include <cs50.c>
#include <stdio.h>

int main(void)
{
    string str = get_string("","Enter your Text: ");
    short w, l, s;
    l = s = 0;
    w = 1;
    for (short i = 0; str[i] != '\0'; i++)
    {
        // letters
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            l++;
        }
        // words
        if (str[i] == ' ')
        {
            w++;
        }
        // sentences
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            s++;
        }
    }
    // calculations
    float S, L, index;
    L = (l / (float)w) * 100;
    S = (s / (float)w) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (short)round(index));
    }
}
