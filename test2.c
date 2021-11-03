#include "tldlist.h"
#include <stdio.h>
#include <string.h>
#include "date.c"
#include <ctype.h>

int main(){

    char* str1 = "ab";
    char* str2 = "ABC";

    printf("%d \n", strncmp(str1, str2, 3));

    for (int i = 0; i< strlen(str2); i++)
    {
        str2[i] = tolower(str2[1]);
    }

    printf("%s", str2);


}