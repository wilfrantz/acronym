
// Credit to tony/NCURSES-Programming-HOWTO-examples on github.
// help function brings up the program documentation file to stdout.
// It uses ncurses to customize the output windown and read from the help
// file located in the .datfiles acronyms directory 

#include <ncurses.h>
#include <stdlib.h>

int help(void){
	int ch, prev, row, col;
	prev = EOF;
	FILE *fp;
	int y, x;

	// Openng the file.
	fp = fopen("/Users/diddy/acronym/.datfiles/help","r");

	if(fp == NULL)
	{
		perror("Cannot open help section file");
		exit(1);
	}

	initscr();				/* Start curses mode */
	getmaxyx(stdscr, row, col);		/* find the boundaries of the screeen */
	while((ch = fgetc(fp)) != EOF)	/* read the file till we reach the end */
	{
		getyx(stdscr, y, x);		/* get the current curser position */
		if(y == (row - 1))			/* are we are at the end of the screen */
		{
			printw("<Press Any Key To Exit>");	/* tell the user to press a key to exit */
			getch();
			clear();				/* clear the screen */
			move(0, 0);			/* start at the beginning of the screen */
		}
		if(prev == '/' && ch == '*')    	/* If it is / and * then only
											 * switch bold on */    
		{
			attron(A_BOLD);			/* cut bold on */
			getyx(stdscr, y, x);		/* get the current curser position */
			move(y, x - 1);			/* back up one space */
			printw("%c%c", '/', ch); 		/* The actual printing is done here */
		}
		else
			printw("%c", ch);
		refresh();
		if(prev == '*' && ch == '/')
			attroff(A_BOLD);        		/* Switch it off once we got *
											 * and then / */
		prev = ch;
	}
	endwin();                       	/* End curses mode */
	fclose(fp);
	return 0;
}
