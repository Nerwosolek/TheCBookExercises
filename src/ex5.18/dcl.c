/*
 * =====================================================================================
 *
 *       Filename:  dcl.c
 *
 *    Description: code for declarations parsing 
 *
 *        Version:  1.0
 *        Created:  2024.04.02 18:46:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tomasz Gieorgijewski (), 
 *   Organization:  Rappsodia Labs
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
int tokentype;          /* type of last token */
char token[MAXTOKEN];   /* last token string */
char name[MAXTOKEN];    /* identifier name */
char datatype[MAXTOKEN];/* data type = char, int, etc. */
char out[1000];         /* output string */


/*  dcl: parse a declarator */
void dcl(void) {

  int ns;
  
  for (ns = 0; gettoken() == '*'; ) /* count *'s */
    ns++;
  dirdcl();
  while(ns-- > 0)
    strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator  */
void dirdcl(void) {

  int type;

  if (tokentype == '(') { /* ( dcl ) */
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME) /* variable name */ 
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");
  while ((type=gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    } 
}

int main() {
  while (gettoken() != EOF) { /* 1st token on line */
    strcpy(datatype, token);  /*  is the datatype */
    out[0] = '\0';
    dcl();
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}


int gettoken(void) {
  int c, getch(void);
  void ungethc(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
}
