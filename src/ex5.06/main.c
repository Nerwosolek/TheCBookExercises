#include "getaline.c"
#include "atoi.c"
#include "itoa.c"
#include "strindex.c"
#include <string.h>


#define MAXLINE 1000
int main(int argc, char const *argv[])
{
    char line[MAXLINE];

    while (getaline(line, MAXLINE) > 0)
    {
        printf("echo: %s", line);
        printf("int: %i\n", atoi(line));
    }
    int n = -5;
    itoa(n, line);
    printf("%i -> %s\n", n, line);
    
    n = 12345;
    itoa(n, line);
    printf("%i -> %s\n", n, line);

    char s[MAXLINE] = "This is a text.";
    char t[MAXLINE] = "is a";
    printf("'%s' in '%s' at %i\n", t, s, strindex(s, t));

    strcpy(t, "This");
    printf("'%s' in '%s' at %i\n", t, s, strindex(s, t));

    strcpy(t, "text.");
    printf("'%s' in '%s' at %i\n", t, s, strindex(s, t));

    strcpy(t, "text.x");
    printf("'%s' in '%s' at %i\n", t, s, strindex(s, t));

    strcpy(t, "TThis");
    printf("'%s' in '%s' at %i\n", t, s, strindex(s, t));

    strcpy(s, "This");
    strcpy(t, "This is.");
    printf("'%s' in '%s' at %i\n", t, s, strindex(s, t));
    return 0;
}
