char *my_strncpy(char *s, char *t, int n)
{
    char* tp = t;
    char* sp = s;
    for(;t - tp < n && *t != '\0';t++)
    {
        *s++ = *t;
    }
    for(;t - tp <= n;t++)
    {
        *s++ = '\0';
    }
    return sp;
}