#include "itoa.c"

int
main(void)
{
    // int n = ~(~0u >> 1);
    // printf("n = %i\n", n);
    // printf("n %% 10 = %i\n", n % 10);
    // printf("-(n %% 10) = %i\n", -(n % -10));
    // printf("n = %i, -n = %i\n", n, -n);
    // printf("n+1 = %i, -(n+1) = %i\n", n+1, -(n+1));
    char s[100];
    int n = 1253;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
    n = -1253;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
    n = ~(~0u >> 1);
    itoa(n, s);
    printf("%i -> %s\n", n, s);
    n = -1;
    itoa(n, s);
    printf("%i -> %s\n", n, s);
}