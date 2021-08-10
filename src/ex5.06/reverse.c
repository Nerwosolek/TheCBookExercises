void reverse(char* s, int len)
{
    char temp;
    if (*(s+len-1) == '\n') len--;
    while(len > 1)
    {
        temp = *s;
        *s = *(s + len - 1);
        *(s + len - 1) = temp;
        s++;
        len -= 2;
    }
}