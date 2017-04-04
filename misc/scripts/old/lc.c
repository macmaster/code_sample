#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	int k = 1;
	int line_count; char c;
	FILE *file;
	
	
	/* check if file comes in */
	if (argc < 2){
		printf("usage: %s filename.txt", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	/* open file */ 
	while(argv[k] != NULL){
		
		file = fopen(argv[k], "r");
		if(file == NULL){
			printf("cannot open file: %s \n", argv[k++]);
		  continue;
		}
	/* scan file lines for nl */
		line_count = 0;
		while((c = fgetc(file)) != EOF){
			if(c == '\n')
				line_count++;
		}
	/* Output & Close file */
		printf("%s: %d \n", argv[k++], ++line_count);	  
		fclose(file);
		
	} 
}
