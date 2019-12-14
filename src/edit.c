
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "../header/utilities.h"
#include "../header/functions.h"

/* The edit function searches the database for a given accronym
 * and open it in a text editor. It receives the acronym
 * to be edited and the acronym file path as pointer strings from the routine. 
 * It checks if the file exists and has write permission to allow
 * the program to perform the edit task.
 * It returns a 0 value for succes and a non-zero for error.*/

int edit (char* acronym, char* acroPath){

	char ch;
	char cmd[SIZE];

	// string variable to hold upper case acronym.
	char upper_arg[SIZE]; 

	// use the system enviroment editor variable
	// to open the file for editing.
	strcpy(cmd,"$EDITOR ");

	// add the file path to the system command.
	strcat(acroPath, acronym);
	strcat(cmd, acroPath);

	// check if the file exists and if the program
	// has write permission.
	// add the system command to the cmd variable.
	if (access(acroPath, F_OK) == 0){

		// execute the system command.
		system(cmd);

	}else{ // if program does not have write permission.

		// turn accronym to upper case letters.
		int i = 0;
		while (acronym[i]) { 
			ch = acronym[i]; 
			upper_arg[i] = toupper(ch); 
			i++; 
		}
		// print error to stdout.
		printf("\nThe file %s does not esist in the database.\n", upper_arg);
		printf("\nUse the -a option to add it.\n");
		exit(1);
	}

	return 0;
}
