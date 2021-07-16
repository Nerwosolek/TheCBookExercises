#include "fahren.h"


int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;  /* lower limit of temperature table*/
    upper = 300;    /* upper limit*/
    step = 20;  /* step size */
    
    fahr = lower;
    printf("%10s%12s\n","Fahrenheit", "Celsius");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%10.0f%12.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
}
