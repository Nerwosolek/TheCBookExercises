//
//  fahren.c
//  HelloWorldC
//
//  Created by Tomasz Gieorgijewski on 04/08/2020.
//  Copyright © 2020 Tomasz Gieorgijewski. All rights reserved.
//

#include "fahren.h"

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;  /* lower limit of temperature table*/
    upper = 300;    /* upper limit*/
    step = 20;  /* step size */
    
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%10.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
}
