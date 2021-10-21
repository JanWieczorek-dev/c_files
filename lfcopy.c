#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT 1024
#include <string.h> 


int readline(char line[], int max);
int writeline(const char line[]);


int main() {

	char input_line[MAX_INPUT]; 

	while (readline( input_line, MAX_INPUT)){
	
		writeline(input_line);
	
	return 0;
	}
}


int readline(char line[], int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}

int writeline(const char line[])
{
	fputs(line, stdout);
	return strlen(line);
}


