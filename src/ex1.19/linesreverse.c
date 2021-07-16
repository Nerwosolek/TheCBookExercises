#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MIN 80  

int getaline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char l[], int length);

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
            reverse(line, len);
            printf("%s", line);
        }
    return 0;
}

void reverse(char s[], int len)
{
    char temp;
    if (s[len-1] == '\n') len--;
    for (int i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

/* getline: read a line into s, return length */
int getaline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1; ++i)
    {
        if ((c=getchar())==EOF) break;
        if (c == '\n') break;
        s[i] = c;
    }
        
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