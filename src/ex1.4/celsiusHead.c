#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = -20;  /* lower limit of temperature table*/
    upper = 30;    /* upper limit*/
    step = 1;  /* step size */
    
    celsius = lower;
    printf("%8s%12s\n","Celsius", "Fahrenheit");
    while (celsius <= upper)
    {
        fahr = celsius * 9.0 / 5.0 + 32;
        printf("%8.0f%12.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
    
}