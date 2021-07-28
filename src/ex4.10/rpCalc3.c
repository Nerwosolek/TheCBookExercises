// This will cover exercises 4-10
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'
#define VAR '$'
#define PRINT_VAR '$'
#define ADDRESS '@'
#define PRINT '?'
#define SINUS 's'
#define POWER 'p'
#define EXP 'e'
#define MAXLEN 1000

int getop(char []);
void push(double);
double pop(void);
double top(void);
double vars[27];
int address(char);

int getaline(int[], int);
int line[MAXLEN];
int line_ind = 0;

int
main(void)
{
    int type;
    double op2;
    int op_int;
    char s[MAXOP];
    
    while(getaline(line, MAXLEN) > 0)
    {
        line_ind = 0;
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
                    vars[address(PRINT_VAR)] = top();
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
    if (v == '$') return 26;
    if (v < 'a') return 0;
    if (v > 'z') return 'z' - 'a';
    return v - 'a';
}

#include<ctype.h>


int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = line[line_ind++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        if (c == '\0') return EOF;
        if (c == VAR || c == ADDRESS) 
        {
            s[0] = line[line_ind++];
            s[1] = '\0';
        }
        return c;
    }
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[line_ind++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[line_ind++]))
            ;
    s[i] = '\0';
    return NUMBER;
}

int getaline(int s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c=getchar())!=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}