#include <stdio.h>
unsigned long long factorial(unsigned long long n)
{
    if (n <= 1)
        return 1;
    return n = n * factorial(n - 1);
}
int main()
{
    unsigned long long ans = factorial(65);
    printf("\n ANS => %llu", ans);
}

//  maximum value that can computer handle is 65
