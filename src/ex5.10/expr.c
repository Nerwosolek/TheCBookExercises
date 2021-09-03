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

int getop(char*);
void push(double);
double pop(void);
double top(void);
double vars[27];
int address(char);

int
main(int argc, char **argv)
{
    int type;
    double op2;
    int op_int;
    // char s[MAXOP];
    if (argc < 2) 
    {
        printf("Not enough arguments.\n");
        return 0;
    }
    while(--argc > 0)
    {
        type = getop(*++argv);
        switch(type)
        {
            case NUMBER:
                push(atof(*argv));
                break;
            case VAR:
                push(vars[address(*argv[1])]);
                break;
            case ADDRESS:
                push(address(*argv[1]));
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
           
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }
    printf("\t%.9g\n", pop());
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

int getop(char* s)
{
    if (!isdigit(s[0]) && s[0] != '.' && s[0] != '\0')
    {
        return s[0];
    }

    if (isdigit(s[0]) || s[0] == '.')
        return NUMBER;
    return 0;
}