#include <stdio.h>

int main(){
    char str[3];
    char *str1 = "abc";

    str[1] = str1[1];

    printf("%c \n", str[1]);
}