#include "day_of_year_ptr.c"
#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("8 maja 1997 jest %d dniem roku.\n", day_of_year(1997, 5, 8));
    int month, day;
    month_day(2021, 188, &month, &day);
    printf("188 dzień 2021 roku to %d.%d\n", day, month);
    return 0;
}
