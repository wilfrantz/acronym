
/* edit.c:
 * The edit function searches the database for a given accronym
 * and open it in a text editor. It receives the acronym
 * to be edited and the acronym file path as pointer strings from the routine. 
 * It checks if the file exists and has write permission to allow
 * the program to perform the edit task.
 * It returns a 0 value for succes and a non-zero for error.
 * */

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "utilities.h"
#include "functions.h"


int edit (char* acronym, char* acroPath){

	// string variable to hold upper case acronym.
	char* upper_arg = (char*) malloc(sizeof(char) * SIZE); 
	char* cmd = (char*) malloc(sizeof(char) * SIZE);

	// use the system enviroment editor variable
	// to open the file for editing.
	strcpy(cmd,"$EDITOR ");

	// add the file path to the system command.
	strcat(acroPath, acronym);
	strcat(cmd, acroPath);

	// check if the file exists and if the program
	// has write permission.
	if (access(acroPath, F_OK) == 0){
		// Execute the system command.
		system(cmd);
	}else{ // if program does not have write permission.
		// turn accronym to upper case letters.
		upper_arg = to_upper(acronym);
		// print error to stdout.
		printf("\nThe file %s does not exist in the database.", upper_arg);
		printf("\nUse the -a option to add it.\n");
		return (-1);
		// exit(1);
	}

	free(upper_arg);
	free(cmd);
	return 0;
}
