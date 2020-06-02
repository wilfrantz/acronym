
/* search.c :
 * The search function seaches the database directoty
 * for an acrony and use the less system command 
 * to display the file to stdout
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"
#include "utilities.h"

int search (char* acro, char* filePath){
	// Acronym to upper case.
	const char* upper_acro = to_upper(acro);
	// Path to the acronym file
	strcat(filePath, acro);

	// Check if the acronym file exist.
	FILE* fp = fopen(filePath, "r+x");
	if(!fp)	{
		perror(upper_acro);
		return -1;
		// exit(EXIT_FAILURE);
	} else {
		char* cmd = (char*) malloc(sizeof(char) * SIZE);
		strcpy(cmd, "less ");
		strcat(cmd, filePath);

		// execute system command.
		system(cmd);

		free(cmd);
	}


	return 0;
}
