#include <stdio.h>
#include <ctype.h>

int htoi(char s[])
{
    int i = 0, n = 0, c;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    for (;  s[i] >= '0' && s[i] <= '9' ||
            s[i] >= 'a' && s[i] <= 'f' ||
            s[i] >= 'A' && s[i] <= 'F';++i)
    {
        c = s[i] - '0';
        if (c >= 0 && c <= 9) 
            n = n * 16 + c;
        else if ((c = tolower(s[i]) - 'a') >= 0 && c <= 5)
            n = n * 16 + c + 10;
        else return n;
    }
    return n;
}

int
main (void)
{
    printf("0xF = %i\n", htoi("0xF"));
    printf("0xf = %i\n", htoi("0xf"));
    printf("0xa = %i\n", htoi("0xa"));
    printf("0x0 = %i\n", htoi("0x0"));
    printf("0x3 = %i\n", htoi("0x3"));
    printf("0xx = %i\n", htoi("0xx"));
    printf("0x387ac = %i\n", htoi("0x387ac"));
    printf("0X387a = %i\n", htoi("0X387a"));
    printf("0x387aqc = %i\n", htoi("0x387aqc"));
    printf("0xFF = %i\n", htoi("0xFF"));
    printf("0xaF9c = %i\n", htoi("0xaF9c"));

    printf("F = %i\n", htoi("F"));
    printf("f = %i\n", htoi("f"));
    printf("a = %i\n", htoi("a"));
    printf("0 = %i\n", htoi("0"));
    printf("3 = %i\n", htoi("3"));
    printf("x = %i\n", htoi("x"));
    printf("387ac = %i\n", htoi("387ac"));
    printf("387a = %i\n", htoi("387a"));
    printf("387aqc = %i\n", htoi("387aqc"));
    printf("FF = %i\n", htoi("FF"));
    printf("aF9c = %i\n", htoi("aF9c"));
}