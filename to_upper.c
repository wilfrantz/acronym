

/* to_upper.c :
 * This function changes the acronyms from lower
 * cases to upper cases
 * */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"
#include "utilities.h"

char* to_upper(char* acronym){
	
	// malloc
	char* upper_acro = (char*) malloc(sizeof(char) * SIZE);

	// Acronym to uppercase.
	int i = 0;
	while (acronym[i]){
		char ch = acronym[i];
		upper_acro[i] = toupper(ch);
		i++;
	}

	return upper_acro;
	// Free malloc
	free(upper_acro);

}

