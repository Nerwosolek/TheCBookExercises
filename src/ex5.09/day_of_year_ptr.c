static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    if (year < 0)
        return -1;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (month < 1 || month > 12)
        return -1;
    if (*(*(daytab + leap)+month) < day)
        return -1;
    p = *(daytab + leap);
    for (; month > 1; month--)
        day += *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;
    *pmonth = -1;
    *pday = -1;
    if (year < 0)
        return;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (yearday > 365 + leap)
        return;
    p = *(daytab + leap);   
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}