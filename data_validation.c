
/* 
 * data_validation.c:
 * This function process user input form the menu fonction
 * (menu.c) for validation.
 * */

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "utilities.h"

int data_validation (int status, const int user_pick){

	// Local variable declaration.
	int temp, count = 0;

	// Data validation process
	while (status!= 1) {   // user generates manual EOF
		int choice = 0;
		while((temp=getchar()) != EOF && temp != '\n');
		printf("\nInvalid entry, try again: ");
		status = scanf("%d", &choice);
		return choice;

		// Force exit on > 4 attempts.
		count++;
		if ( count > 2 ){
			printf("\nYou have exceeded the number of allowed attempts\n");
			exit(2);
		}
	}

	return user_pick;
}
