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
    
    for(int i = 0; i < height; i++)
    {
        // spaces
        for(int s = i; s < height-1; s++)
        {
            printf(" ");
        }
        for(int l = 0; l <= i; l++)
        {
            printf("#");
        }

        printf("  ");

        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}