#include<stdio.h>

int
any(char s1[], char s2[])
{
    int i, k;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k]) return i;
        }
    }
    return -1;
}

int
main(void)
{
    char tekst[] = "Ala mota kota i coz!";
    char znaki[] = "87b";
    printf("position=%i\n", any(tekst, znaki));
}