#include<stdio.h>
void reverse(char s[], int len);

void reverse(char s[], int len)
{
    char temp;
    if (s[len-1] == '\n') len--;
    for (int i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

void
itoa (int n, char s[])
{
    int i, sign;
    if (n < 0)
        sign = -1;
    else
        sign = 1;
    i = 0;
    do {
        s[i++] = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign == -1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
}