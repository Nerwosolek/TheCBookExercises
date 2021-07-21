#include<stdio.h>
#include "../ex3.04/itoa.c"

void
itob (int n, char s[], int b)
{
    int i, sign, r;
    if (n < 0)
        sign = -1;
    else
        sign = 1;
    i = 0;
    do {
        r = sign * (n % b);
        s[i++] = r < 10 ? sign * (n % b) + '0' : sign * (n % b) - 10 + 'A';
    } while ((n /= b) != 0);
    if (sign == -1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
}
