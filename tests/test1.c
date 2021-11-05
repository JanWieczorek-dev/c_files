#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char * string1 = "abcd";

    for( int i =0; i< strlen(string1); i++)
    {
        string1[i] = tolower(string1[i]);


    }

    printf("%s", string1);

}