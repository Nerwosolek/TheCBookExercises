#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 20

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
        if (c == '\t' || c == ' ' || c == '\n') 
        {
            if (state == IN) 
            {  
                state = OUT;
                ++whist[nc];
                nc = 0;
            }
        }
        else {
            ++nc;          
            state = IN;
        }
    }
    printf("Words lengths histogram:\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (whist[i] >= 0) 
        {
            printf("%2d: ", i);
            for (int k = 0; k < whist[i]; k++)
                printf("#");
            printf(" %d\n",whist[i]);
        }
        
    }
}