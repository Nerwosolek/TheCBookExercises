#include<string.h>
#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], int maxlines, char* storage, int maxchars)
{
    int len, nlines;
    char *p = storage, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || p + len > storage + maxchars)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}