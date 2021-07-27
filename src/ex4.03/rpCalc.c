#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'
#define VAR '$'
#define ADDRESS '@'
#define PRINT '?'
#define SINUS 's'
#define POWER 'p'
#define EXP 'e'

int getop(char []);
void push(double);
double pop(void);
double top(void);
double vars[26];
int address(char);

int
main(void)
{
    int type;
    double op2;
    int op_int;
    char s[MAXOP];

    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case VAR:
                push(vars[address(s[0])]);
                break;
            case ADDRESS:
                push(address(s[0]));
                break;
            case PRINT:
                printf("\t%.8g\n", top());
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op_int = (int)pop();
                if (op_int != 0)
                    push((int)pop() % op_int);
                else
                    printf("error: zero divisor\n");
                break;
            case SINUS:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POWER:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '=':
                op2 = pop();
                vars[(int)pop()] = op2;
                push(op2); // new value of variable pushed on stack for having it as a part of expression.
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// stack
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top(void)
{
    if (sp > 0)
        return val[sp-1];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
    
}

int address(char v)
{
    if (v < 'a') return 0;
    if (v > 'z') return 'z' - 'a';
    return v - 'a';
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        {
            if (c == VAR) 
            {
                s[0] = getch();
                s[1] = '\0';
            }
            else if (c == ADDRESS)
            {
                s[0] = getch();
                s[1] = '\0';
            }
            return c;
        }
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}