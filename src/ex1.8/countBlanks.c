#include <stdio.h>

void main(void)
{
    int c, wh;
    wh = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n') ++wh;
    }
    printf("\n%d\n", wh);
}