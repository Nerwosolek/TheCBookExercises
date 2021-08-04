void strcat_ptr(char *s, char *t)
{
    while(*s++);
    s--;
    while((*s++ = *t++));
}