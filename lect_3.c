#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int *int_array = malloc(atoi(argv[1])* sizeof(int));
	
		int value = 0;
		while (value < atoi(argv[1])){
			*int_array = value;
			printf("%p %d\n", &int_array[i], int_array[i]);
			value ++
			int_array++
		}
}		
			