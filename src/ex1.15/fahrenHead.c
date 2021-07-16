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
        celsius = fahrToCels(fahr);
        printf("%10.0f%12.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
}

float fahrToCels(float f)
{
    return 5 * (f - 32) / 9;
}
