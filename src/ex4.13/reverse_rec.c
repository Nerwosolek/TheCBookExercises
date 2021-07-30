void reverse(char s[], int len, int i)
{
    char temp;
    if (s[len-1] == '\n') len--;
    if (i < len - 3)
        reverse(s, len - 1, i + 1);
    temp = s[i];
    s[i] = s[len-1];
    s[len-1] = temp;
}