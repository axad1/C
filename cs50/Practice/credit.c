#include<stdio.h>
#include<ctype.h>
int main()
{
    long card;
    scanf("%li", &card);
    printf("card = %li\n", card);
    long x = card;
    int len = 0;
    while(x>0)
    {
        x = x/10;
        len++;
    }
    printf("len = %i\n", len);
    if(len != 13 && len != 15 && len != 16)
    {
        printf("INVALIDa\n");
        return 0;
    }

    int m1,m2,d1,d2,sum1,sum2;
    sum1 = sum2 = 0;
    x = card;
    do
    {
        m1 = x % 10;
        sum1 = sum1 + m1;
        x = x / 10;

        m2 = x % 10;
        m2 = m2 * 2;
        x = x / 10;
        d1 = m2 / 10;
        d2 = m2 % 10;

        sum2 = sum2 + d1 + d2;
    }
    while(x > 0);

    int total = sum1 + sum2;
    if(total % 10 != 0)
    {
        printf("INVALIDb\n");
        return 0;
    }

    x = card;
    do
    {
        x = x/10;
    }
    while(x > 100);

    if(x/10 == 5 && (x%10 > 0 && x%10 < 6))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if(x/10 == 3 && (x%10 == 4 || x%10 == 7))
    {
        printf("AMEX\n");
        return 0;
    }
    else if(x/10 == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALIDc\n");
    }

}