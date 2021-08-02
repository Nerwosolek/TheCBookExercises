#include "getint.c"

#define SIZE 10

int
main(void)
{
    int n, array[SIZE], s;
    for (n = 0; n < SIZE && (s = getint(&array[n])) != EOF; n++)
    {
        printf("array[%i] = %i, status = %i\n", n, array[n], s);
    }
}