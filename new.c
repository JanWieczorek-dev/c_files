#include <stdio.h>
#include <stdlib.h>




int main(){
 
int *arr = malloc(sizeof(int)*10);
arr[2] = 4;


printf("%d \n", arr[2]);

}