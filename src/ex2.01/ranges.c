#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("char min = %d\n", CHAR_MIN);
    printf("char max = %d\n", CHAR_MAX);
    printf("unsigned char max = %d\n", UCHAR_MAX);
    printf("short min = %d\n", SHRT_MIN);
    printf("short max = %d\n", SHRT_MAX);
    printf("unsigned short max = %d\n", USHRT_MAX);
    printf("int min = %d\n", INT_MIN);
    printf("int max = %d\n", INT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("long min = %ld\n", LONG_MIN);
    printf("long max = %ld\n", LONG_MAX);
    printf("unsigned long max = %lu\n", ULONG_MAX);
    printf("float min = %.45e\n", FLT_MIN);
    printf("float max = %.10f\n", FLT_MAX);
    printf("radix = %d\n", FLT_RADIX);
    printf("float mantissa (%d base) digits = %d\n",FLT_RADIX, FLT_MANT_DIG);
    printf("float decimal digits = %d\n", FLT_DIG);
    printf("float epsilon = %.20f\n", FLT_EPSILON);
    printf("min float exponent = %d\n", FLT_MIN_10_EXP);
    printf("max float exponent = %d\n", FLT_MAX_10_EXP);
    printf("double min = %.60f\n", DBL_MIN);
    printf("double max = %.60f\n", DBL_MAX);
    printf("min double exponent = %d\n", DBL_MIN_10_EXP);
    printf("max double exponent = %d\n", DBL_MAX_10_EXP);
    printf("double mantissa (%d base) digits = %d\n",FLT_RADIX, DBL_MANT_DIG);
    printf("double decimal digits = %d\n", DBL_DIG);
    printf("double epsilon = %.20f\n", DBL_EPSILON);
    printf("long double min = %.60Lf\n", LDBL_MIN);
    printf("long double max = %.60Lf\n", LDBL_MAX);
    printf("min long double exponent = %d\n", LDBL_MIN_10_EXP);
    printf("max long double exponent = %d\n", LDBL_MAX_10_EXP);
    printf("long double mantissa (%d base) digits = %d\n",FLT_RADIX, LDBL_MANT_DIG);
    printf("long double decimal digits = %d\n", LDBL_DIG);
    printf("long double epsilon = %.20Lf\n", LDBL_EPSILON);
    printf("long double digits = %i\n", __SIZEOF_LONG_DOUBLE__);
    float k = (float)6.0*8.0;
    long double p = 1.0;
    float *pk;
    pk = &k;    
    printf("k = %.10e, address = %p, address of pointer = %p\n", k, pk, &pk);
    printf("dereferencing of p - %f", *pk);
}

