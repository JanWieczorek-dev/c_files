#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int readline(char line[], int max){

		if (fgets(line, max, stdin) == NULL)
			return 0;
		else
			return strlen(line);
	}


	int writeline(const char line[]){

		fputs(line, stdout);
	
		return strlen(line);
	}


int main() {

	char input_line[INT_MAX]; 

	while (readline( input_line, INT_MAX) != 0){
	
		writeline(input_line)
	}
}