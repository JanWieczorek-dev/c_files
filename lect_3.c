#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

		int* int_array = malloc(*argv[1] * sizeof(int));
		
		for (int i = 0; i < *argv[1]; i++){
			int_array[i] = i;
			printf("%p %d\n", &int_array[i], int_array[i]);
		}
}		
			