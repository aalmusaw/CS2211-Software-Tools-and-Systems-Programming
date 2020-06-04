# makefile for asn5

mymemory: main.o memory.o bst.o datatype.o list.o
	gcc -o mymemory main.o memory.o bst.o datatype.o list.o
main.o: main.c memory.h list.h
	gcc -c main.c
memory.o: memory.c memory.h bst.h
	gcc -c memory.c
bst.o: bst.c bst.h datatype.h
	gcc -c bst.c
datatype.o: datatype.c datatype.h
	gcc -c datatype.c
list.o: list.c list.h datatype.h memory.h
	gcc -c list.c
clean:
	rm -f *.o