#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    FILE *in = fopen("card.raw", "r");
    if(in == NULL)
    {
        printf("File opening error\n");
        return 1;
    }
    uint8_t buffer[512];
    char name[8];
    int count = -1;
    FILE *out = NULL;
    while (fread(buffer, sizeof(buffer), 1, in))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (out != NULL)
            {
                fclose(out);
            }
            count++;
            sprintf(name, "%03d.jpg", count);
            out = fopen(name, "w");
        }
        if (out != NULL)
        fwrite(buffer, sizeof(buffer), 1, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
