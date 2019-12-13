
#include "../header/utilities.h"
#include "../header/functions.h"

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/* The edit function searches the database for a given accronym
 * and open it in a text editor. It receives the acronym
 * to be edited and the acronym file path as pointer strings from the routine. 
 * It checks if the file exists and has write permission to allow
 * the program to perform the edit task.
 * It returns a 0 value for succes and a non-zero for error.*/

int edit (char* acronym, char* acroPath){

	char cmd[SIZE];
	char upper_arg[SIZE];

	// check if the file exists and if the program
	// has write permission.
	if (access(acronym, W_OK) != -1){
		// get the command line variable.
		strcpy(cmd,"$EDITOR ");
		// add the file path to the system command.
		strcat(cmd, acroPath);

		// execute the sustem command.
		system(cmd);


		// turn accronym to upper case letters.
		int i = 0;
		while (acronym) { 
			char ch = acronym[i]; 
			upper_arg[i] = toupper(ch); 
			i++; 
		}

	}else{ // if program does not have write permission.

		// print error to stdout.
	}

	return (0);
}
