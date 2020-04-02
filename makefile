
whts : acronym.o add.o delete.o edit.o help.o
	gcc -g3 -lncurses -Wall -Wextra acronym.c help.c add.c delete.c edit.c -o whts 

acronym.o : acronym.c
	gcc -g -c acronym.c

add.o : add.c
	gcc -g -c add.c

delete.o : delete.c
	gcc -g -c delete.c

edit.o : edit.c
	gcc -g -c edit.c

help.o : help.c
	gcc -g -c help.c

clean :
	rm *.o
