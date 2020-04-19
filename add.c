
/*
 * add.c:
 * This function add an acronym to the database,
 * it receives the string with the acronym and 
 * the path to the database.
 * It returns 0 on success and a non-zero on failure! 
 * */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "utilities.h"

int add (char* arg, char* path){

	// turn accronym to upper case letters.
	const char* upper_arg = to_upper(arg);
	// file to acronym file
	const char* filePath = strcat(path, arg);
	// create the acronym file
	FILE* fp = fopen(filePath, "w+x");

	if (!fp){ // check if file exists
		perror(upper_arg);
		exit(EXIT_FAILURE);
	} else { 
		size_t size = SIZE; 
		char* buffer = (char*) malloc(sizeof(char) * size);
		// User prompt for acronym definition.
		printf("\nInsert definition for %s : \n> ", upper_arg);
		int bytes_read = getline(&buffer, &size, stdin);
		if (bytes_read == -1){ // User input error checking.
			perror("ERROR!");
			exit(EXIT_FAILURE);
		}
		// write to acronynm file
		fprintf(fp, "\n\n\t%s :\n \t\t%s\n\n\n", upper_arg, buffer);

		free(buffer);
	}

	fclose(fp);

	return 0;
}
