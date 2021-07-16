#include<stdio.h>

unsigned
invert(unsigned x, int p, int n)
{
    unsigned ones = ~(~0 << n) << (p-n+1); // 00000111110000 - n ones at position p
    unsigned ohs = ~ones; // 111111000001111 - n zeros at position p
    return ( ones | x ) & ( ~x | ohs );
}

int
main(void)
{
    int n = 3, p = 6;
    unsigned x = 0114734; //  100110011_101_1100 -> 100110011_010_1100 => 114654
    unsigned expected = 0114654;
    printf("x = %i, exp = %i\n", x, expected);
    printf("invert(x,6,3) = %u\n", invert(x, p, n));

    n = 6;
    p = 5;
    x = 0021511; // 0010001101001001 -> 0010001101_110110 => 021566
    expected = 0021566;
    printf("x = %i, exp = %i\n", x, expected);
    printf("invert(x,%i,%i) = %u\n", p, n, invert(x, p, n));
    // 9078 -> 1000
}