#include <stdio.h>

typedef struct date {
    int dd;
    int mm;
    int yy;
} date;

int month_2_days[12] = {
    // 1    2    3    4
       0,   31,  59,  90,
    // 5    6    7    8
       120, 151, 181, 212,
    // 9    10   11   12
       243, 273, 304, 334
};

// determine if a year is leap year
int is_leap(int yr)
{
    if( (yr % 400 == 0) || (yr % 4 == 0 && yr % 100 != 0) )
        return 1;
    else
        return 0;
}

// determine if a date is after the leap day of the same year
int after_leap_day(date *d)
{
    if (is_leap(d->yy) && (d->mm >= 3))
        return 1;
    return 0;
}

// calculate total days relative to ref_year
int get_total_days(date *d, int ref_year)
{
    int days = 0, i;
    
    // transform month to days
    days = month_2_days[d->mm - 1];

    // include leap days (not include the leap day in d->yy)
    for (i = ref_year; i < d->yy; i ++)
        if (is_leap(i))
            days +=1;

    // include leap day in d->yy
    if (after_leap_day(d))
        days += 1;
        
    // calculate sum
    days = days + d->dd + (d->yy - ref_year) * 365;
    
    printf("%d\n", days);
    return days;
}

int get_dates_diff(date *d1, date *d2)
{
    int ref_year;
    
    ref_year = (d1->yy > d2->yy) ? d2->yy : d1->yy;
    
    return (get_total_days(d1, ref_year) - get_total_days(d2, ref_year));
}


int
main()
{
    date d1, d2;
    puts("Enter first date: month day year\n");
    scanf("%d %d %d", &d1.mm, &d1.dd, &d1.yy);
    
    puts("Enter second date: month day year\n");
    scanf("%d %d %d", &d2.mm, &d2.dd, &d2.yy);
    
    int diff_in_days = get_dates_diff(&d1, &d2);
    
    if (diff_in_days > 0)
        printf("d1 larger than d2 by %d days\n", diff_in_days);
    else if (diff_in_days < 0)
        printf("d1 smaller than d2 by %d days\n", -diff_in_days);
    else
        printf("d1 equal to d2\n");
    
    return 0;
}