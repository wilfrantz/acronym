/* 
 * Menu.c :
 * Menu fucntion prints out program main menu
 * */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "functions.h"
#include "utilities.h"

int menu (char* argv, char* pathname){

	printf("\nWelcome to the Acronym Database.\n");

	printf("\n%s \nCopyright 2019-2020 Wilfrantz DEDE.\n\n%s is free software, covered by the GNU General Public License, and you are\nwelcome to change it and/or distribute copies of it under certain conditions.\nThere is absolutely no warranty for %s.\n", VERSION, argv, argv);

	printf("\n\t\t\tCurrent command line arguments\n\
			---------------------------------->\n\
			-a add			Add a new acronym.\n\
			-e edit			Edit a acronym\n\
			-r remove		remove an acronym\n");

	/*
	// Loading animation 
	for ( int loop = 0; loop < 3; ++loop) {
	for ( int each = 0; each < 3; ++each) {
	printf ("\rLoading %.*s   \b\b\b", each, "...");
	fflush (stdout);// Force printing as no newline in output
	sleep (1);
	}
	}
	*/
	printf ( "\n");

	int choice;

	//////////////////////
	// Print main menu //

	do {
		printf("\nMenu:\n");
		printf("\n\
				1- Add a new acronym\n\
				2- Edit an acronym\n\
				3- Remove an acronym\n\
				4- Search for an acronym.\n\
				5- Quit the program\n\n\
				> ");
		bool to_validate = scanf("%d", &choice);
		choice = data_validation(to_validate, choice);

		switch (choice){

			case 1 : 
				{
					printf("\nEnter acronym : ");
					scanf("%s", argv);
					add(argv, pathname);
					break;
				}
			case 2 : 
				{
					printf("\nEnter acronym to edit: ");
					scanf("%s", argv);
					edit(argv, pathname);
					break;
				}
			case 3 : 
				{
					printf("\nEnter acronym to Remove : ");
					scanf("%s", argv);
					del(argv, pathname);
					break;
				}
			case 4 :
				{
					printf("\nEnter acronym to search : ");
					scanf("%s", argv);
					search (argv, pathname); // #TODO
					break;
				}
			case 5 : 
				{
					printf("\nQuitting program ...\n");
					sleep(1);
					system("clear");
					printf("\nProgram ended.\n");
					exit(0);
					break;
				}

			default : printf("\nInvalid option. Try again: \n") ;
					  break;
		}
	} while (choice != 5);

	return 0;
}

