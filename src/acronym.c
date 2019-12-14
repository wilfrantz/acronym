

/* 
 * C program to store, edit and display acronyms.
 * I have written this progrom to help me keep up
 * with the multiples acronyms that I have to deal 
 * with in the IT field, specially with system and networking
 * topics.
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "../header/functions.h"
#include "../header/utilities.h"


int main (int argc, char** argv){
	// local variable declaration.
	char filePath[SIZE];
	char cmd[SIZE];

	strcpy(filePath, "../.datfiles/");

	/*
	   current command line arguments
	   ---------------------------------------
	   -a add			Add  a new acronym.
	   -e edit			Edit a acronym
	   -r remove		remove an acronym
	   */

	// process condition.
	if (argc > 3){
		printf("\nBad Usage.\n");
		printf("\nUsage: %s -a [acronym], -s [acronym] or -r [acronym] \n or simply type %s for program documentation]\n",argv[0], argv[0]);
		exit(1);
	}

	// process condition and control.
	else if(argc == 1){
		// #TODO
		// if the program is executed without
		// arguments print program documentation to stdout.
		printf("\nThis is the help section.\n");
		exit(0); // exit program with success.

	}else if (argc == 2){

		char ch;
		char upper_acro[SIZE];
		char acronym[SIZE];
		int i = 0;
		strcpy(acronym, argv[1]);

		// Turn acronym to uppercase letters.
		while (acronym[i]){
			ch = acronym[i];
			upper_acro[i] = toupper(ch);
			i++;
		}
		strcat(filePath, argv[1]);

		// check is the file acronym file exist.
		if (access(filePath, F_OK) != 0){
			printf("\nThe acronym %s is not in your database.\n", upper_acro);
			exit(1);
		}
		/* find  and display the acronym file from the
		 * program database (.datfiles direcoty) */
		strcpy(cmd, "less ");
		strcat(cmd, filePath);
		system(cmd);

		exit(0);
	}

	// variable to store the acronym.
	// if the program is run with parsing.
	char acronym[SIZE];
	strcpy(acronym, argv[2]);

	for (int i = 1; i < argc; i+=2) {
		/* check for valid flags (first char should be '-' for flags) */
		if (argv[i][0] != '-') {
			printf("\nbad option character...should be \"-\"\n");
			exit(2);
		}

		/* check for valid flag value and take appropriate action */
		switch (argv[i][1]) {

			case 'b': system (cmd);
					  break;
			case 'a': add(acronym, filePath);
					  break;
			case 'r': del(acronym, filePath);
					  break;
			case 'e': edit (acronym, filePath);
					  break;
			default: printf("\nBad option...\nShould be \"-a\", \"-r\", \"s\" or  \"-h\"\n");
					 exit(3);
					 break;
		}
	}

	return 0;
}
