

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "../header/functions.h"
#include "../header/utilities.h"

/*
 * This function add an acronym to the database,
 * it receives the string with the acronym and 
 * the path to the database.
 * It returns 0 for success and a non-zero for failure! */

int add (char* arg, char* path){

    // path to the acronym file.
    char* file = strcat(path, arg);

    // local variable
    char ch;
    char upper_arg[SIZE];
    int i = 0;

    // check if the acronym file exist.
    if (access(file, F_OK) != -1){ // file exists.

	// turn accronym to upper case letters.
	// set as a convention.
	while (arg[i]) { 
	    ch = arg[i]; 
	    upper_arg[i] = toupper(ch); 
	    i++; 
	}
	// send error message to stdout.
	printf("\nThe acronym %s exist in the database.", upper_arg);
	printf("\nRun the program with %s as argument\n", upper_arg);
	printf("\nUsage: whts %s\n", upper_arg);
	exit(3);
    }else{ // file does not exists

	// turn accronym to upper case letters.
	// set as a convention.
	while (arg[i]) { 
	    ch = arg[i]; 
	    upper_arg[i] = toupper(ch); 
	    i++; 
	}
	// file pointer variable 
	FILE* fp = fopen (file, "w");
	char str[256];

	// User prompt for acronym definition.
	// stores the information in the array string.
	printf("\nInsert acronym related info:\n");
	fgets(str, sizeof(str), stdin);

	// write acronym and definition to file in the .datfiles
	// directory.
	fprintf(fp, "\n\n\t%s :\n \t\t%s\n\n\n", upper_arg, str);

	//close file
	fclose(fp);
    }

    return 0;
}
