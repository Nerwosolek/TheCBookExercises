#include<ctype.h>
#include<stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c) && c != EOF)
    {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int buf;

int getch(void)
{
    char temp = buf;
    if (buf != '\0')
    {
        buf = '\0';
        return temp;
    }
    return getchar();
}

void ungetch(int c)
{
    if (buf != '\0')
        printf("ungetch: pushed back character already exists\n");
    else
        buf = c;
}