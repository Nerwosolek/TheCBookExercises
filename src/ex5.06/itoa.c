#include "reverse.c"
void
itoa (int n, char* s)
{
    char *sp = s;
    int i, sign;
    if (n < 0)
        sign = -1;
    else
        sign = 1;
    do {
        *s++ = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign == -1)
        *s++ = '-';
    *s = '\0';
    reverse(sp, s - sp);
}