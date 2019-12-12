
#include "../header/utilities.h"
#include "../header/functions.h"

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/* This function delete an acronym from the acronym database.
 * It receives the acronym to delete and the path to the acronym
 * database from the routine.
 * It checks if the acronym file exist within the database
 * print an error message if or delete the file.
 * The function return 0 for success and non-zero for failure*/

int del (char* arg, char* filePath) {

	// get the right path to the file. 
	strcat(filePath, arg);
	// variable to hold the system command.
	char cmd[SIZE];
	char upper_arg[SIZE];

	// check if the acronym file exist.
	// before we try to delete.
	if (access(filePath, F_OK)!= -1){ // if file exists.
		char ch;
		int i = 0;
		// get the system command.
		strcpy(cmd, "rm ");
		// get the path to the file to delete.
		strcat(cmd, filePath);
		// execute de command.
		system (cmd);

		// turn accronym to upper case letters.
		while (arg[i]) { 
			ch = arg[i]; 
			upper_arg[i] = toupper(ch); 
			i++; 
		}
		printf("\nAccronym %s deleted from the database.\n", upper_arg);
	}else{ // if file does not exist.
		// print error message if the file
		// does not exist in the file path.
		printf("\nThe acronym %s does not exist in the database\n", upper_arg);
		exit(1); // exit with error.
	}
	return 0;
}
