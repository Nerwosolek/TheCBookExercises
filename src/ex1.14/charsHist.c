#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 26

int main(void) 
{
    char c;
    int nc;
    nc = 0;
    int whist[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++) 
        whist[i] = 0;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') 
        {
            ++whist[c-'a'];
        }
    }
    printf("chars frequencies histogram:\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
            printf("%2c: ", 'a'+i);
            for (int k = 0; k < whist[i]; k++)
                printf("#");
            printf(" %d\n",whist[i]);
    }
}