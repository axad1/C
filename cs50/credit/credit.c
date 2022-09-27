#include <cs50.c>
#include <stdio.h>
int get_length(unsigned long long x);
int main(void)
{
    long long card = get_long_long("Enter card number: ");
    // get length of card
    int len = get_length(card);
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    unsigned long long x = card;
    int m1, m2, d1, d2, sum1, sum2;
    sum1 = sum2 = 0;
    do
    {
//    	m1 = mod1
//		m2 = mod2
        // get last digit
        m1 = x % 10;
        sum1 += m1;
        // remove last digit
        x /= 10;
        // get second last digit and multiply by 2
        m2 = x % 10;
        // remove second last digit
        x /= 10;
        // multiply mod by two
        m2 *= 2;
        // get first digit of the number
        d1 = m2 / 10;
        // get second digit of the number
        d2 = m2 % 10;
        // make sum2
        sum2 += d1 + d2;
    }
    while (x > 0);

    int total = sum1 + sum2;
    // total's last digit should be zero according to Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // get the first 2 starting digits
    unsigned long long start = card;
    do
    {
        start /= 10;
    }
    while (start > 100);

    // check the first digits for MASTERCARD 51,52,53,54,55
    if (start / 10 == 5 && (start % 10 > 0 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    // check for the AMERICAN EXPRESS 34 or 37
    else if (start / 10 == 3 && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
        return 0;
    }
    // check for the VISA first digit must be 4
    else if (start / 10 == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
    }

}
// MAIN ENDS

// length function start
int get_length(unsigned long long x)
{
    int l = 0;
    while (x > 0)
    {
        x /= 10;
        l++;
    }
    return l;
}
