#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MIN 80  

int getaline(char line[], int maxline);
void copy(char to[], char from[]);
int remove_trails(char l[], int length);

/* print longest input line */
int main()
{
    int len;    // current line length
    int max;    // maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE];  // longest line saved here

    max = 0;
    while((len = getaline(line, MAXLINE)) > 0)
        {
            if (remove_trails(line, len) > 0)
                printf("%s\n", line);
        }
    return 0;
}

int remove_trails(char s[], int len)
{
    int i;
    for(i = len-1; i > 0 && (s[i] == '\n' || s[i] == '\t' || s[i] == ' ');--i)
        ;
    if (s[i] == '\n') s[i] = '\0';
    else s[++i] = '\0';
    return i;
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}