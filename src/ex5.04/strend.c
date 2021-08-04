int strend(char *s, char *t)
{
    char* sp = s, *tp = t;
    while(*s) s++;
    while(*t) t++;
    for(;s - sp >= 0 && t - tp >= 0; s--, t--)
    {
        if (*t != *s) return 0;
    }
    if (t - tp >= 0) return 0;
    return 1;
}