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
    char day_str[3];
    char month_str[3];
    char year_str[5];

    for(int i = 0; i < 2; i++){
        day_str[i] = datestr[i];
    }
    for(int i = 3; i < 5; i++){
        month_str[i-3] = datestr[i];
    }
    for(int i = 6; i < 10; i++){
        year_str[i-6] = datestr[i];
    }

    day_str[2] = '\0';
    month_str[2] = '\0';
    year_str[4] = '\0';


    if ((date = (Date *) malloc(sizeof(int)*3))!= NULL)
    {
        date->day = atoi(day_str);
        date->month = atoi(month_str);
        date->year = atoi(year_str);
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