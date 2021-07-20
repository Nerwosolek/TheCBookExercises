#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXLINE 100

void expand(char s1[],char s2[])
{
    int i,j,c;
    j = 0;
    for (i = 0; s1[i] != '\0'; i++)
    {
        // printf("i = %i, s1[i]=%c\n", i, s1[i]);
        if (s1[i] == '-' && i > 0 && ((isdigit(s1[i-1])&&isdigit(s1[i+1]))||
            (isalpha(s1[i-1]) && isalpha(s1[i+1]))))
        {
            for(c=s1[i-1]+1;c<=s1[i+1];c++)
                s2[j++] = c;
            ++i;
        }
        else s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

int main(void)
{
    char s1[MAXLINE],s2[MAXLINE];

    strcpy(s1, "a-z");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "-a-z");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "-a-9-");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "-0-1a-c");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "a-a!-*");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "b-a0-3--");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "a-b-c");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);

    strcpy(s1, "c-z-b");
    expand(s1,s2);
    printf("%s -> %s\n",s1, s2);
    
    return 0;
}


