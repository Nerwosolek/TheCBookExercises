#include<stdio.h>
/* getline: read a line into s, return length */
int getaline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c=getchar())!=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}