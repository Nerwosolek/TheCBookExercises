#include<stdio.h>

int
lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int
main(void)
{
    printf("A -> %c\n", lower('A'));
    printf("Z -> %c\n", lower('Z'));
    printf("D -> %c\n", lower('D'));
    printf("l -> %c\n", lower('l'));
    printf("2 -> %c\n", lower('2'));
    return 0;
}