#include<stdio.h>
/* getline: read a line into s, return length, pointers version*/
int getaline(char* s, int lim)
{
    char* sp = s;
    int c, i;
    while(s - sp < lim - 1 && (c=getchar())!=EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - sp;
}