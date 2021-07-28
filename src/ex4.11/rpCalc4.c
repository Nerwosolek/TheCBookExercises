// This will cover exercises 4-8 to 4-9
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

int getop(char []);
void push(double);
double pop(void);
double top(void);
double vars[27];
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
                printf("\t%.9g\n", pop());
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
    if (v == '$') return 26;
    if (v < 'a') return 0;
    if (v > 'z') return 'z' - 'a';
    return v - 'a';
}

#include<ctype.h>

int getch(void);

int getop(char s[])
{
    int i;
    int c;
    static int prevc = 0;
    // printf(" %i", prevc);
    if (prevc == 0)
    {
        c = getch();
    }
    else {
        c = prevc;
        prevc = 0;
    }
    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        {
            if (c == VAR || c == ADDRESS) 
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
        prevc = c;
    return NUMBER;
}

int buf;

int getch(void)
{
    char temp = buf;
    if (buf != '\0')
    {
        buf = '\0';
        return temp;
    }
    return getchar();
}