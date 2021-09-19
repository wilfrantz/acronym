
whts : acronym.o add.o delete.o edit.o help.o menu.o data_validation.o search.o to_upper.o #msg.o
	gcc -g3 -lncurses -Wall -Wextra acronym.c help.c add.c delete.c search.c edit.c menu.c to_upper.c data_validation.c -o whts

acronym.o : acronym.c
	gcc -g -c acronym.c

add.o : add.c
	gcc -g -c -std=c11 add.c

delete.o : delete.c
	gcc -g -c delete.c

edit.o : edit.c
	gcc -g -c edit.c

help.o : help.c
	gcc -g -c help.c

menu.0 : menu.c
	gcc -g -c menu.c

to_upper.o : to_upper.c
	gcc -g -c to_upper.c

search.o : search.c
	gcc -g -c search.c

data_validation.o : data_validation.c
	gcc -g -c data_validation.c

#msg.o : msg.c
#gcc -g -c msg.c

clean :
	rm *.o
