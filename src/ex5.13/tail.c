#include "tail.h"

#define BUFFERSIZE 500
#define DEFAULT 10

char *lines_buffer[BUFFERSIZE];
int p = 0;

int
main(int argc, char **argv)
{
    int n = DEFAULT;
    if (argc > 1)
    {
        if (argv[1][0] == '-' && isdigit(argv[1][1]))
        {
            n = atoi(argv[1]+1);
        }
        else
        {
            printf("Syntax: tail -n\n");
            return -1;
        }
    }
    // writelines
    int line_cnt = readlines(lines_buffer, BUFFERSIZE);
    // n, BUFFERSIZE, p, line_cnt
    // n = min(n, BUFFERSIZE, line_cnt)
    // start = p - n, jesli start < 0 to start = BUFFERSIZE - start.

    n = MIN(MIN(n, BUFFERSIZE), line_cnt);
    // printf("n = %i, p = %i\n", n, p);
    int start = p - n;
    if (start < 0) start = BUFFERSIZE + start;
    // printf("start = %i\n", start);
    for (int i = start; n > 0; i = (i + 1) % BUFFERSIZE, --n)
        printf("%s\n", lines_buffer[i]);
}

#define MAXLEN 1000
int readlines (char *lineptr[], int buf_size)
{
    int len, nlines;
    char line[MAXLEN];
    char *temp;

    nlines = 0;
    while((len = getaline(line, MAXLEN)) > 0)
    {
        if (nlines < buf_size)
        {
            temp = malloc(MAXLEN * sizeof(char) + 1);
            if (temp == NULL) return -1;
        }
        else
        {
            temp = lineptr[p];
        }
        line[len-1] = '\0'; 
        strcpy(temp, line);
        lineptr[p] = temp;
        nlines++;
        p = (p + 1) % buf_size;
    }
    return nlines;
}

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