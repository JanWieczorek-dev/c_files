#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int *int_array[atoi(argv[1])] ;
		
		for (int i = 0; i < atoi(argv[1]); i++){
			int_array[i] = i;
			printf("%p %d\n", &int_array[i], int_array[i]);
		}
}		
			