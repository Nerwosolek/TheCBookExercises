#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line size */
static int tab_stop = 10;
int getaline(char in[], int len);
int entab(char line[], int len, int* tab_stops, int tabs_len);
int parse_input(int argc, char** argv, int* stops);

int main(int argc, char** argv)
{
    int len;    // current line length
    char line[MAXLINE]; // current input line
    int* stops = malloc(sizeof(int));
    *stops = tab_stop;
    // printf("stops: %p\n", stops);
    int stop_len = parse_input(argc, argv, stops);

    while((len = getaline(line, MAXLINE)) > 0)
    {
        entab(line, len, stops, stop_len);
        printf("%s", line);
    }
    return 0;
}

int entab(char line[], int len, int* stops, int stops_len)
{
    char temp[MAXLINE]; 
    int i = 0;
    int k = 0;
    int pos = 1;
    int blanks = 0;
    int tabs = 0;
    int n = *stops;
    // printf("entab, n = %i\n", n);
    // printf("entab, stops_len = %i\n", stops_len);
    while (line[i] != '\0')
    {
        if (line[i] == ' ')
        {
            if (i < n)
            {
                blanks++;
            } else {
                blanks = 0;
                tabs++;
                if (--stops_len > 0) n += *++stops;
                else n += *stops;
            }
            // printf("entab, n = %i\n", n);
            // printf("entab, stops_len = %i\n", stops_len);
        }
        else 
        {
            for (;tabs>0;--tabs)
                temp[k++] = '\t';
            if (line[i] == '\t')
                blanks = 0;
            else
                for (;blanks>0;--blanks)
                    temp[k++] = ' ';
            temp[k++] = line[i];
            if (line[i] == '\n')
                pos = 0;
            else if(line[i] == '\t')
                pos = pos + (n - (pos - 1)%n)-1;
        }
        ++i;
        ++pos;
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

int parse_input(int argc, char** argv, int* stops)
{
    int i = 0, start_col = -1, rep_col = 0;
    if (argc > 1) {
        stops = malloc(sizeof(int) * (argc - 1));
        argv++;
        if (stops == NULL) {
            exit(EXIT_FAILURE);
        }
        while (--argc > 0)
        {
            // printf("argv:%s(%c,%c)\n",*argv, **argv, (*argv)[1]);
            if (isdigit(**argv))
            {                
                *(stops + i++) = atoi(*argv++);
            }
                
            else if (**argv == '-' && isdigit((*argv)[1]))
            {
                start_col = atoi(*argv+1);
                argv++;
            }
            else if (**argv == '+' && isdigit((*argv)[1]))
            {
                rep_col = atoi(*argv + 1);
                argv++;
            }
            else
            {
                // printf("Invalid tab argument.");
                exit(EXIT_FAILURE);
            }
          
            // printf("arg: %i\n", n);
        }
        if (start_col > -1)
        {
            // printf("i = %i\n", i);
            stops = realloc(stops, sizeof(int) * (start_col + 1));
            stops[start_col] = rep_col;
            if (start_col >= i) 
            {
                for(int k = i; k < start_col; k++) stops[k] = stops[i-1];
            }
            i = start_col + 1;
        }

        // printf("stops: %p\n", stops);
        // printf("-m: %i, +n: %i\n", start_col, rep_col);
        // printf("stops_len = %i\n", i);
    } else i = 1;
    return i;
}
