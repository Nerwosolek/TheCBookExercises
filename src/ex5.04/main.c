#include "strend.c"
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char s[50] = "Tekst z koncem.";
    char t[50] = "cem.";

    if (strend(s, t))
        printf("Jest.\n");
    else 
        printf("Nie ma.\n");
    
    strcpy(t, "cem");
    if (strend(s, t))
        printf("Jest.\n");
    else 
        printf("Nie ma.\n");
    
    strcpy(t, "Tekst z koncem.");
    if (strend(s, t))
        printf("Jest.\n");
    else 
        printf("Nie ma.\n");

    strcpy(t, "Tekst z koncem.x");
    if (strend(s, t))
        printf("Jest.\n");
    else 
        printf("Nie ma.\n");

    strcpy(t, "_Tekst z koncem.");
    if (strend(s, t))
        printf("Jest.\n");
    else 
        printf("Nie ma.\n");
}