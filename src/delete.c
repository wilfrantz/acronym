
#include "../header/utilities.h"
#include "../header/functions.h"

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int del (char* arg) {
	char cmd[SIZE];
	char path[SIZE];

	char ch;
	char upper_arg[SIZE];
	int i = 0;

	strcpy(path, "../.datfiles/");
	strcat(path, arg);
	strcpy(cmd, "rm ");

	strcat(cmd, path);
	system (cmd);

	// turn accronym to upper case letters.
	while (arg[i]) { 
		ch = arg[i]; 
		upper_arg[i] = toupper(ch); 
		i++; 
	}
	printf("\nAccronym %s deleted from you database directoty.\n", upper_arg);
	return 0;
}
