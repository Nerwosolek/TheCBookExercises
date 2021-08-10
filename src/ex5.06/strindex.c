int strindex(char* s, char* t)
{
    int i,j,k, r = -1;
    char *sj = s, *sp = s;
    char *pt = t;
    while(*s)
    {
        for(sj = s, pt = t; *pt && *sj == *pt; pt++, sj++)
            ;
        if (pt > t && !*pt)
            return s - sp;
        s++;
    }
    return -1;
}