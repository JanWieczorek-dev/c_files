#include <stdio.h>
#include <stdlib.h>



int main() {

    char input_char;
	int counter = 0;
	
    while (scanf("%c", &input_char) == 1 ){
		
		if (input_char == "\n"){
			counter ++;
		}
		printf("%c counter: %d", input_char, counter);
		
	}
	
}
