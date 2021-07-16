#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
int tab_stop = 10;
int getaline(char in[], int len);
int detab(char line[], int len, int n);

int main()
{
    int len;    // current line length
    int max;    // maximum length seen so far
    char line[MAXLINE]; // current input line

    max = 0;
    while((len = getaline(line, MAXLINE)) > 0)
        {
            detab(line, len, tab_stop);
            printf("%s", line);
        }
    return 0;
}

int detab(char line[], int len, int n)
{
    char temp[MAXLINE]; 
    int i = 0;
    int k = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '\t')
        {
            for(int c = k % n; c < n; c++)
            {
                temp[k] = '.';
                ++k;
            }
            ++i;
        }
        else
        {
            temp[k] = line[i];
            ++k;
            ++i;
        }
    }
    temp[k] = '\0';
    for(k = 0; temp[k] != '\0'; k++)
    {
        line[k] = temp[k];
    }
    line[k] = '\0';
    return k;
}

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
