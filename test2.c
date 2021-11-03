#include "tldlist.h"
#include <stdio.h>
#include <string.h>
#include "date.c"
#include <ctype.h>

int main(){

    char* str1 = "ab";
    char* str2 = "ABC";
    int i =0;
    char* new_str[3];

    printf("%d \n", strncmp(str1, str2, 3));

    while (i < 3)
    {
        new_str[i] = tolower(str2[i]);
        i++;

    }
    
 
    printf("%s", str2);


}