#include "tldlist.h"
#include <stdio.h>
#include <string.h>
#include "date.c"


int main(){

    char date[10];
    char * string = "05/11/2018 www.intel.com";
    char tld[20];
    Date processed_date;

    sscanf(string, "%s %*s.%*s.%s", date, tld);


    processed_date = *date_create(date);

    printf("%s %s", tld, date );
    



}