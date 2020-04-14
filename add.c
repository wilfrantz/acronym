
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "utilities.h"

int add (char* arg, char* path){

	// turn accronym to upper case letters.
	char* upper_arg = to_upper(arg);

	char* filePath = strcat (path, arg);

	FILE* fp = fopen(filePath, "w+x");
	if (!fp){
		// send error message to stdout.
		perror(upper_arg);
		exit(EXIT_FAILURE);
	} else {
		char* buffer = (char*) malloc(sizeof(char*) * SIZE);
		
		// User prompt for acronym definition.
		printf("\nInsert definition for %s : \n> ", upper_arg);
		fgets(buffer, sizeof(buffer), stdin);

		// write to acronynm file
		fprintf(fp, "\n\n\t%s :\n \t\t%s\n\n\n", upper_arg, buffer);

		free(buffer);
	}

	// close file
	fclose(fp);
	return 0;
}
