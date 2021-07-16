#include<stdio.h>

unsigned
rightrot(unsigned x, int n)
{
    int carry;
    unsigned int mask = 1;
    unsigned int sig1 = ~(~0u >> 1);
    // printf("sig1 = %u\n", sig1);
    // printf("sig1 = %u\n", 1 << 16);
    // printf("sig1 * 1 = %u\n", sig1 * 1);
    // printf("sig1 * 0 = %u\n", sig1 * 0);
    for (size_t i = 0; i < n; i++)
    {
        carry = x & mask;
        x >>= 1;
        x += sig1 * carry;
    }
    return x;
}

int
main(void)
{
    printf("5 ROR 1 = %u\n", rightrot(5u,1));
    unsigned expected = ~(~0u >> 1);
    expected += ~(~0u >> 1) >> 1;
    expected += ~(~0u >> 1) >> 2;
    expected += 127u >> 3;
    printf("127 ROR 3 = %u, expected = %u\n", rightrot(127u, 3), expected);
    expected = ~(~0u >> 1) + (~(~0u >> 1) >> 3) + (~(~0u >> 1) >> 4) + 2;
    printf("166 ROR 6 = %u, expected = %u\n", rightrot(166u, 6), expected);
    return 0;
}