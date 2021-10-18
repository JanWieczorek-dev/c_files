#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int *int_array = malloc(atoi(argv[1])* sizeof(int));
	int *ptr = &int_array;
	
		int value = 0;
		while (value < atoi(argv[1])){
			*ptr = value;
			printf("%p %d\n", &int_array[value], int_array[value]);
			value ++;
			ptr++;
		}
}		
			