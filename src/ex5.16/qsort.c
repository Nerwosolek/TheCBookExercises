#include<stdio.h>
#include <string.h>
#include <ctype.h>



#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

void _qsort(void *lineptr[], int left, int right,
           int (*comp)(const void *, const void *), int reverse);

int numcmp(const char *,const char *);
int fstrcmp(const char *, const char*);

int
main(int argc, char **argv)
{
    int nlines;
    int numeric = 0; // 1 if numeric sort
    int reverse = 0; // 1 if reverse order
    int fold = 0; // 1 if lower and upper case folded together
    int dir = 0; // 1 if in directory order
    for (int i = 1; i < argc; i++)
    {     
        if (strcmp(argv[i], "-n") == 0)
            numeric = 1;
        if (strcmp(argv[i], "-r") == 0)
            reverse = 1;
        if (strcmp(argv[i], "-f") == 0)
            fold = 1;
        
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        _qsort((void **) lineptr, 0, nlines-1, (int (*)(const void*,const void*))(numeric ? numcmp : (fold ? fstrcmp : strcmp)), reverse);
        putchar('\n');
        writelines(lineptr, nlines);
        return 0;
    } 
    else 
    {
        printf("input too big to sort\n");
        return 1;
    }
}

void _qsort(void *v[], int left, int right, int (*comp)(const void *,const void *), int reverse)
{
    int i, last;
    void swap(void *[], int, int);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(!reverse ? v[i] : v[left], !reverse ? v[left] : v[i]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    _qsort(v, left, last-1, comp, reverse);
    _qsort(v, last+1, right, comp, reverse);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#include<stdlib.h>

int numcmp(const char *s1,const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int fstrcmp(const char *s1, const char *s2)
{
    unsigned char c1, c2;
    do
    {
        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
        if (c1 == '\0')
            return c1 - c2;
        printf("%i ", (c1-c2));
    } while(c1 == c2);
    return c1 - c2;
}

#define MAXLEN 1000
int getaline(char *, int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getaline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = malloc(len * sizeof(char))) == NULL)
            return -1;
        line[len-1] = '\0'; // delete newline
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
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