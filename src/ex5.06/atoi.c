int atoi(char *s)
{
    int n = 0;
    while(*s >= '0' && *s <= '9')
        n = 10 * n + (*s++ - '0');
    return n;
}