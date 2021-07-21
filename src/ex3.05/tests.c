#include "itob.c"

int
main(void)
{
    char s[100];
    int n = 3147;
    itob(n, s, 10);
    printf("%i -> %s\n", n, s);

    itob(n, s, 8);
    printf("%i -> %s\n", n, s);

    itob(n, s, 16);
    printf("%i -> %s\n", n, s);

    itob(n, s, 9);
    printf("%i -> %s\n", n, s);

    itob(n, s, 32);
    printf("%i -> %s\n", n, s);

    n = 126349;
    itob(n, s, 32);
    printf("%i -> %s\n", n, s);

    n = 126349;
    itob(n, s, 16);
    printf("%i -> %s\n", n, s);
}
