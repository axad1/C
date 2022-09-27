#include <stdio.h>
int main()
{
    int height;
    do
    {
        printf("height: ");
        scanf("%i", &height);
    }
    while(height < 1 || height > 8);
    

    for (int i = 0; i < height; i++)
    {
        // spaces
        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
        
    }
}