#include <stdio.h>  
#include<string.h>  


struct name {
const char * first_name;
const char * last_name;
};
typedef struct name name;


 int compare_first (name name1, name name2){
	 return strcmp (name1.first_name, name2.first_name);
 }
 
 
 int compare_last (name name1, name name2){
	 return strcmp (name1.ast_name, name2.last_name);
 }

int main() {
	
name names[4] = {
 {"Grace", "Hopper"},
 {"Dennis", "Ritchie"},
 {"Ken", "Thompson"},
 {"Bjarne", "Stroustrup"}
};

qsort(names, 4, sizeof(name), compare_last); 	 

for (int i = 0; i < 4; i++){
	printf("%s\n", names[i].last_name);
}

printf("%s", "by first name:");

qsort(names, 4, sizeof(name), compare_last); 	

for (int i = 0; i < 4; i++){
	printf("%s\n", names[i].first_name);
}
}
