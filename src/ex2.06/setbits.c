#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned ones = ~(~0 << n) << (p-n+1); // 00000111110000 - n ones at position p
    unsigned ohs = ~ones; // 111111000001111 - n zeros at position p
    return (ones | x) & (ohs | (y << (p-n+1)));   
}

int
main(void)
{
    int n = 3, p = 6;
    unsigned x = 0114734;
    unsigned y = 0012573;
    unsigned expected = x - 32;
    printf("x = %i, y = %i, exp = %i\n", x, y, expected);
    printf("setbits(x,6,3,y) = %u\n", setbits(x, p, n, y));

    n = 6;
    p = 5;
    x = 0021511;
    y = 0144523;
    expected = 0021523;
    printf("x = %i, y = %i, exp = %i\n", x, y, expected);
    printf("setbits(x,%i,%i,y) = %u\n", p, n, setbits(x, p, n, y));
}