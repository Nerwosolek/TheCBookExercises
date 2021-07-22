#include "../ex3.04/itoa.c"

void
itoa2 (int n, char s[], int l)
{
    int i, sign;
    sign = (n < 0) ? -1 : 1;
    i = 0;
    do {
        s[i++] = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign == -1)
        s[i++] = '-';
    while (i < l)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s, i);
}