
whts : acronym.o add.o delete.o edit.o
	gcc acronym.c add.c delete.c edit.c -o whts 

acronym.o : acronym.c
	gcc -c acronym.c

add.o : add.c
	gcc -c add.c

delete.o : delete.c
	gcc -c delete.c

edit.o : edit.c
	gcc -c edit.c


clean :
	rm *.o
