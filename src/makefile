
whts : acronym.o add.o delete.o edit.o
	gcc -o whts acronym.c add.c delete.c edit.c

acronym.o : acronym.c
	gcc -c acronym.c
add.o : add.c
	gcc -c add.c
delete.o : delete.c
	gcc -c delete.c
edit.o : delete.c
	gcc -c delete.c

clean :
	rm *.o
