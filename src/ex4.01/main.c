#include<stdio.h>
#include "getaline.c"
#include "strrindex.c"
#define MAXLINE 1000

char pattern[] = "ould";

int
main(void)
{
    char line[MAXLINE];
    int found = 0;
    int ind = -1;

    while (getaline(line, MAXLINE) > 0)
    {
        if ((ind = strrindex(line, pattern)) >= 0)
        {
            printf("(%i): %s", ind, line);
            found++;
        }
    }
    return found;
}