#include<stdio.h>

int
bitcount(unsigned x)
{
    int c = 0;
    while (x > 0)
    {
        ++c;
        x &= (x-1);
    }
    return c;
}

int main(void)
{
    printf("111010101100 has %u bits\n", bitcount(0b111010101100u));
    printf("1110101000111000111010 has %u bits\n", bitcount(0b1110101000111000111010u));
}