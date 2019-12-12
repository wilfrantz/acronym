
#include "../header/functions.h"
#include "../header/utilities.h"

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/*
 * This function add an acronym to the database,
 * it receives the string with the acronym and 
 * the path to the database.
 * It returns 0 for success and a non-zero for failure! */

int add (char* arg, char* path){

    // path to the acronym file.
    char* file = strcat(path, arg);

    // check if the acronym file exist.
    if (access(file, F_OK) != -1){
	char ch;
	char upper_arg[SIZE];
	int i = 0;

	// turn accronym to upper case letters.
	while (arg[i]) { 
	    ch = arg[i]; 
	    upper_arg[i] = toupper(ch); 
	    i++; 
	}
	// send error message to stdout.
	printf("\nThe acronym %s exist in the database.", upper_arg);
	printf("\nRun program with %s argument\n", upper_arg);
	exit(3);
    }else{

	// file pointer variable 
	FILE* fp = fopen (file, "w");

	char cmd [SIZE];
	// Get program script to perform the task.
	strcpy(cmd, "../shelDir/add.sh ");
	strcat (cmd, arg);

	// execute the system command.
	system(cmd);

	//close file
	fclose(fp);
    }

    return 0;
}
