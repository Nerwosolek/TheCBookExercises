#include<stdio.h>

void
itoa (int n, char s[])
{
    static int i = 0; 
    int sign;
    if (n < 0)
        sign = -1;
    else
        sign = 1;
    i = 0;
    if (sign == -1)
        s[i++] = '-';
    if ((n / 10) != 0)
        itoa(n / 10,  s);
    s[i++] = sign * (n % 10) + '0';
    s[i] = '\0';
}