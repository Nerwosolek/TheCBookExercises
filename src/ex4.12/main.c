#include "itoa_rec.c"
#define MAX 1000

int
main(void)
{
    char s[MAX];
    int n = -28559;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
    n = 1;
    itoa(n, s);
    printf("%i -> %s\n", n, s);

    n = 1929010;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
    n = -4713123;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
    n = -5;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
}