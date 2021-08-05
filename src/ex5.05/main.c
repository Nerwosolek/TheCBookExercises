#include<stdio.h>
#include<string.h>
#include "strncpy.c"
#include "strncat.c"
#include "strncmp.c"

int
main(void)
{
    char s[50];
    char t[50] = "This is text.";
    int n = 5;

    my_strncpy(s, t, n);
    printf("%s -> %s(%i)\n", t, s, n);

    strcpy(s, "0123456789012345678901234567890123456789");
    n = 13;

    
    printf("%s -> %s(%i)\n", t, my_strncpy(s, t, n), n);

    n = 25;

    printf("%s -> %s(%i)\n", t, my_strncpy(s, t, n), n);
    strcpy(t, "At the end.");
    printf("%s;",s);
    printf("%s -> %s(%i)\n", t, my_strncat(s, t, n), n);

    strcpy(t, ".");
    printf("%s;",s);
    printf("%s -> %s(%i)\n", t, my_strncat(s, t, n), n);

    strcpy(s, "Text.");
    strcpy(t, "Additional.");
    n = 3;
    printf("%s;",s);
    printf("%s -> %s(%i)\n", t, my_strncat(s, t, n), n);

    strcpy(s, "Text.");
    strcpy(t, "Additional.");
    n = 23;
    printf("%s;",s);
    printf("%s -> %s(%i)\n", t, my_strncat(s, t, n), n);

    strcpy(s, "Text.");
    strcpy(t, "");
    n = 2;
    printf("%s;",s);
    printf("%s -> %s(%i)\n", t, my_strncat(s, t, n), n);

    strcpy(s, "Compare me.");
    strcpy(t, "Compare me.");
    n = 22;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "Compare me.");
    strcpy(t, "Compare me.");
    n = 4;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "Compare me.");
    strcpy(t, "Compare");
    n = 4;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "Compare me.");
    strcpy(t, "Compare");
    n = 4;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "Compare me.");
    strcpy(t, "Compare");
    n = 24;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "We differ here.");
    strcpy(t, "We differ there.");
    n = 10;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "We differ here.");
    strcpy(t, "We differ there.");
    n = 11;
    printf("%s == %s?(%i) -> %i\n", s, t, n, my_strncmp(s, t, n));

    strcpy(s, "We differ here.");
    strcpy(t, "We differ there.");
    n = 20;
    printf("%s == %s?(%i) -> %i\n", t, s, n, my_strncmp(t, s, n));
    return 0;
}