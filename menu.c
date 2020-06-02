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

	//msg(); // display program info.

	int choice;
	do {
		printf("\nMenu:\n");
		printf("\n\
				[1] Add a new acronym\n\
				[2] Edit an acronym\n\
				[3] Remove an acronym\n\
				[4] Search for an acronym.\n\
				[5] Quit the program\n\n\
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

