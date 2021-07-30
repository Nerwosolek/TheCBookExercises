#define swap(t,x,y) { t temp; temp = x; x = y; y = temp;}
#include<stdio.h>

int
main(void)
{
    int k = 5, l = 12;
    printf("before swap\n");
    printf("k = %i,l = %i\n", k, l);
    swap(int,k,l);
    printf("after swap\n");
    printf("k = %i,l = %i\n", k, l);
    double w = 4.5, z = 6.7;
    swap(double, w, z);
    printf("w = %g,z = %g\n", w, z);
}
