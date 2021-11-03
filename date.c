#include "date.h"
#include<stdio.h>
#include <stdlib.h>



struct date
{
    int day;
    int month;
    int year;

};


Date *date_create(char *datestr){

    Date *date;
    int day_;
    int month_;
    int year_;


    if (sscanf(datestr, "%d/%d/%d", &day_, &month_, &year_) != 3){
        return NULL;
   }



    if ((date = (Date *) malloc(sizeof(int)*3))!= NULL)
    {
        date->day = day_;
        date->month =  month_;
        date->year = year_;
    }
    else {
        return NULL;
    }
    return date;
}



Date *date_duplicate(Date *d){
    Date *date_duplicate;

    if ((date_duplicate = (Date*)malloc(sizeof(int)*3))!= NULL){
        date_duplicate->day = d->day;
        date_duplicate->month = d->month;
        date_duplicate->year = d->year;
    }
    else{
        return NULL;
    }
    return date_duplicate;
}

int date_compare(Date *date1, Date *date2){

    if(date1->year > date2->year){
        return 1;
    }
    else if (date1->year < date2->year)
    {
        return -1;
    }

    if(date1->month > date2->month){
        return 1;
    }
    else if (date1->month < date2->month)
    {
        return -1;
    }

    if(date1->day > date2->day){
        return 1;
    }
    else if (date1->day < date2->day)
    {
        return -1;
    }

    return 0;


}

void date_destroy(Date *d){
    free(d);
}
                                  