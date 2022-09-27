#include <stdio.h>
#include <cs50.c>
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("enter cents : ");
    }
    while(cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters;
    quarters = cents / 25;
    return quarters;
}
int calculate_dimes(int cents)
{
    int dimes = cents / 10;
    return dimes;
}
int calculate_nickels(int cents)
{
    int nickels = cents / 5;
    return nickels;
}
int calculate_pennies(int cents)
{
    return cents;
}
int main()
{
    int cents = get_cents();
    int dimes,quarters,nickels,pennies,coins;
    
    quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    pennies = calculate_pennies(cents);

    coins = quarters + dimes + nickels + pennies;

    printf("%i", coins);
}