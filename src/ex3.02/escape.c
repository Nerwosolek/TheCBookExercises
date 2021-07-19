#include<stdio.h>
#include<string.h>

void
escape(char s[], char t[])
{
    int i = 0, j = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\t':
            s[j++] = '\\';
            s[j++] = 't'; 
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\r':
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\f':
            s[j++] = '\\';
            s[j++] = 'f';
            break;
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        ++i;
    }
    s[j] = '\0';
}

void
prison(char s[], char t[])
{
    int i = 0, j = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '\\')
        {
            switch (t[++i])
            {
            case 't':
                s[j++] = '\t';
                break;
            case 'n':
                s[j++] = '\n';
                break;
            case 'b':
                s[j++] = '\b';
                break;
            case 'r':
                s[j++] = '\r';
                break;
            case 'f':
                s[j++] = '\f';
                break;
            case '0':
                s[j++] = '\0';
                break;
            default:
                s[j++] = t[i];
                break;
            }
            ++i;
        }
        else 
        {
            s[j++] = t[i++];
        }
        
    }
    s[j] = '\0';
}

int
main(void)
{
    char tekst[50] = "Ala ma kota\t";
    char tekstv[50];
    escape(tekstv, tekst);
    printf("tekst: [%s] -> [%s]\n", tekst, tekstv);
    strcpy(tekst, "Ala\b\bdam ma psa\t.");
    escape(tekstv, tekst);
    printf("tekst: [%s] -> [%s]\n", tekst, tekstv);
    memcpy(tekst, "Joh\\nny Mnemonic\rJasiek.", 23);
    escape(tekstv, tekst);
    printf("tekst      : [%s]\n -> [%s]\n", tekst, tekstv);
    printf("%s\n", tekst);
    printf("%s\n", tekstv);

    strcpy(tekst, "Ala ma kota\\t.");
    prison(tekstv, tekst);
    printf("tekst: [%s] -> [%s]\n", tekst, tekstv);

    strcpy(tekst, "Ala ma kota\\n.");
    prison(tekstv, tekst);
    printf("tekst: [%s] -> [%s]\n", tekst, tekstv);
}