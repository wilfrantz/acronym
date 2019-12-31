
// help function brings up the program documentation file to stdout.
// It uses ncurses to customize the output windown and read from the help
// file located in the .datfiles acronyms directory 
// Credit to tony/NCURSES-Programming-HOWTO-examples on github.

#include <ncurses.h>
#include <stdlib.h>

int help(void){

	// Local variable declaration.
	int ch, prev, row, col;
	prev = EOF;

	// file pointer.
	FILE *fp;
	int y, x;

	// Openng the file.
	fp = fopen("/Users/diddy/acronym/.datfiles/help","r");

	// Process condition.
	if(fp == NULL)
	{
		perror("Cannot open help section file");
		exit(1);
	}

	/* Start curses mode */
	initscr();
	/* find the boundaries of the screeen */
	getmaxyx(stdscr, row, col);		
	/* read the file till we reach the end */
	while((ch = fgetc(fp)) != EOF){
		/* get the current curser position */
		getyx(stdscr, y, x);		
		/* are we are at the end of the screen */
		if(y == (row - 1)){
			/* tell the user to press a key to exit */
			printw("<Press Any Key To Exit>");	
			getch();
			/* clear the screen */
			clear();				
			/* start at the beginning of the screen */
			move(0, 0);			
		}

		/* If it is / and * then only * switch bold on */    
		if(prev == '/' && ch == '*'){
			attron(A_BOLD);			/* cut bold on */
			getyx(stdscr, y, x);		/* get the current curser position */
			move(y, x - 1);			/* back up one space */
			printw("%c%c", '/', ch); 		/* The actual printing is done here */
		}else{
			printw("%c", ch);
			refresh();
		}

		if(prev == '*' && ch == '/')
			/* Switch it off once we got * and then / */
			attroff(A_BOLD);        		

		prev = ch;
	}

	// End curses mode 
	endwin(); 
	// close the file.
	fclose(fp);

	return 0;
}
