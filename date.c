#ifndef _DATE_H_INCLUDED_
#define _DATE_H_INCLUDED_
#include <stdlib.h>
#include <string.h>
#include "date.h"

struct date
{
    int year;
    int month;
    int day;
};



/*
* date_create creates a Date structure from `datestr`
* `datestr' is expected to be of the form "dd/mm/yyyy"
* returns pointer to Date structure if successful,
* NULL if not (syntax error)
*/
Date *date_create(char *datestr)
{

    Date *date = malloc(sizeof(Date));
    char year[6], month[4], day[4];

    day[0] = datestr[0];
    day[1] = datestr[1];
    day[2]='\0';
    date->day = strtol(day, NULL, 10);

    month[0] = datestr[3];
    month[1] = datestr[4];
    month[2]='\0';
    date->month = strtol(month, NULL, 10);

    year[0] = datestr[6];
    year[1] = datestr[7];
    year[2] = datestr[8];
    year[3] = datestr[9];
    year[4]='\0';
    date->year = strtol(year, NULL, 10);

    return date;
}
/*
* date_duplicate creates a duplicate of `d'
* returns pointer to new Date structure if successful,
* NULL if not (memory allocation failure)
*/
Date *date_duplicate(Date *d)
{
    Date *date = malloc(sizeof(Date));
    date->year = d->year;
    date->day = d->day;
    date->month = d->month;
    return date;
}
/*
* date_compare compares two dates, returning <0, 0, >0 if
* date1<date2, date1==date2, date1>date2, respectively
*/
int date_compare(Date *date1, Date *date2)
{
    if (date1->year > date2->year)
    {
        return 1;
    }
    else if (date1->year < date2->year)
    {
        return -1;
    }
    else
    {
        if (date1->month > date2->month)
        {
            return 1;
        }
        else if (date1->month < date2->month)
        {
            return -1;
        }
        else
        {
            if (date1->day > date2->day)
            {
                return 1;
            }
            else if (date1->day < date2->day)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
/*
* date_destroy returns any storage associated with `d' to the system
*/
void date_destroy(Date *d)
{
    free(d);
}

#endif /* _DATE_H_INCLUDED_ */