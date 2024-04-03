/*
 * =====================================================================================
 *
 *       Filename:  getch.c
 *
 *    Description: getch/ungetch 
 *
 *        Version:  1.0
 *        Created:  2024.04.03 16:54:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tomasz Gieorgijewski (), 
 *   Organization:  Rappsodia Labs
 *
 * =====================================================================================
 */
#include "getch.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
