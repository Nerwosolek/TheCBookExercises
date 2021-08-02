#include "getfloat.c"

#define SIZE 10

int
main(void)
{
    int n, s;
    double array[SIZE];
    for (n = 0; n < SIZE && (s = getfloat(&array[n])) != EOF; n++)
    {
        printf("array[%i] = %.7g, status = %i\n", n, array[n], s);
    }
}