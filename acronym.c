/*
 * acronym.c :
 * C program to save, edit and display acronyms.
 * I have written this progrom to help me keep up
 * with the multiples acronyms that I have to deal
 * with in the IT field, specially with system and networking
 * */


/* Current command line arguments
 * ---------------------------------------
 *  -a add		Add  a new acronym
 *  -e edit		Edit a acronym
 *  -r remove		remove an acronym
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "utilities.h"


int main (int argc, char** argv){
	// NOTE: Improve this line and improve protability 
	// database directory path.
	char pathDir[] = ".datfiles/";

	char* acronym = (char*) malloc(sizeof(char) * SIZE);

	// if CLA > 3, exit with error.
	if (argc > 3){
		printf("\nToo many arguments !!! \nUsage: \
				%s -a [acronym], -e [acronym] or -r [acronym] \n", argv[0]);

		exit(EXIT_FAILURE);
	}else if(argc == 1){
		menu(argv[0], pathDir); // menu fuction call.
		exit(0);
	}else if (argc == 2){
		strcpy(acronym, argv[1]);
		search (acronym, pathDir);
		exit(0);
	}else{
		strcpy(acronym, argv[2]);
		for (int i = 1; i < argc; i+=2) {
			// Check for valid flags.
			if (argv[i][0] != '-') {
				printf("\nbad option... should be \"-\"\n");
				exit(2);
			}

			// Take appropriate action.
			switch (argv[i][1]) {
				case 'a': add(acronym, pathDir);
						  break;
				case 'r': del(acronym, pathDir);
						  break;
				case 'e': edit(acronym, pathDir);
						  break;
				case 'h':
						  printf("ncdu <options> <directory>\n\n");
						  printf("  -h, This help message\n");
						  printf("  -a                         Add an acronym.\n");
						  printf("  -r                         Remove an acronym.\n");
						  printf("  -e                         Edit an acronym.\n");
						  printf("  -v						   Print version\n");
						  exit(0);
				default: printf("\nBad option...\nShould be \"-a\", \"-r\", \"e\" or \"h\"\n");
						 exit(3);
						 break;
			}
		}
	}

	free(acronym);

	return 0;
}
