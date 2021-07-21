#include "itoa2.c"

int main(void)
{
    char s[100];
    int n = 1253;
    int l = 10;
    itoa2(n, s, l);
    printf("%i -> %s\n", n, s);
    n = -1253;
    l = 12;
    itoa2(n, s, l);
    printf("%i -> %s\n", n, s);
    n = ~(~0u >> 1);
    l = 2;
    itoa2(n, s, l);
    printf("%i -> %s\n", n, s);
    n = -1;
    l = 5;
    itoa2(n, s, l);
    printf("%i -> %s\n", n, s);
    return 0;
}
