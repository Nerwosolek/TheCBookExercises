#include "reverse_rec.c"
#include<stdio.h>
#include<string.h>
#define MAX 1000

int
main(void)
{
    char s[MAX] = "Test1";
    int len = 5;
    reverse(s, len, 0);
    printf("result: %s\n", s);
    strcpy(s, "Litwo! Ojczyzno moja!");
    len = strlen(s);
    reverse(s, len, 0);
    printf("result: %s\n", s);
    strcpy(s, "M");
    len = strlen(s);
    reverse(s, len, 0);
    printf("result: %s\n", s);
}