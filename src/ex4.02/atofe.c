#include<ctype.h>

double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign, exp;

    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+'||s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+'||s[i] == '-')
        i++;
    for (exp = 0.0; isdigit(s[i]); i++)
    {
        exp = 10.0 * exp + (s[i] - '0');
    }
    val = sign * val / power;
    for(double n = 1.0; n <= exp; n += 1.0)
    {
        val = (exp_sign == -1) ? val / 10.0 : val * 10.0;
    }
    return val;
}