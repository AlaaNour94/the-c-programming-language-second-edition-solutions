/* Exercise 5-9. Rewrite the routines day_of_year pointers instead of indexing*/

#include <stdio.h>

static int year_month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap_year_month_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int *daytab[2] = {year_month_days, leap_year_month_days};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    printf("%d\n", day_of_year(2000, 2, 10));
    return 0;
}

int day_of_year(int year, int month, int day)
{

    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}