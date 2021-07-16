#include <stdio.h>

main()
{
    int c, p = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || p != ' ')
            putchar(c);
        p = c;
    }
}