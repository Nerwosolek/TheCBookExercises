#include <stdio.h>
#define IN 1
#define OUT 0

int main(void)
{
    char c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') 
        {
            if (state == IN) 
            {
                putchar('\n');
                state = OUT;
            }
        }
        else {
            putchar(c);
            state = IN;
        }
    }
}