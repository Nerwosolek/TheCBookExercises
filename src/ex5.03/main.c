#include<stdio.h>
#include "strcat_ptr.c"
#define MAXLEN 1000
int
main(void)
{
    char s[MAXLEN] = "This is old.";
    strcat_ptr(s, "");
    printf("%s\n", s);
}