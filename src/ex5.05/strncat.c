char *my_strncat(char *s, char *t, int n)
{
    char* tp = t;
    char* sp = s;
    while(*s) s++;
    for(;t - tp < n && *t != '\0';t++)
    {
        *s++ = *t;
    }
    *s = '\0';

    return sp;
}