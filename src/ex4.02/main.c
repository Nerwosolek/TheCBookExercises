#include<stdio.h>
#include "atofe.c"
int
main(void)
{
    char* s;
    s = "-1.2e3";
    printf("%s -> %g\n", s, atof(s));
    s = "13e4";
    printf("%s -> %g\n", s, atof(s));
    s = "13e";
    printf("%s -> %g\n", s, atof(s));
    s = "-11.32";
    printf("%s -> %g\n", s, atof(s));
    s = "-11.";
    printf("%s -> %g\n", s, atof(s));
    s = "-11.e";
    printf("%s -> %g\n", s, atof(s));
    s = "-127.23e105";
    printf("%s -> %g\n", s, atof(s));
    s = "27.23e-11";
    printf("%s -> %g\n", s, atof(s));
    s = "-3427.23e-16";
    printf("%s -> %g\n", s, atof(s));
    return 0;
}