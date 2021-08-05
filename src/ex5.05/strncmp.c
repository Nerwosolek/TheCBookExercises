int my_strncmp(char *s, char *t, int n)
{
    for (int i = 0; *s == *t && i < n-1; i++, s++, t++)
    {
        if (*s == '\0')
            return 0;
    }
    return (*s - *t);
}