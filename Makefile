CC=gcc
CFLAGS=Wall

main: main.o linkedlist.o
	gcc main.o linkedlist.o -o main

main.o: main.c
	gcc -c main.c -o main.o

linkedlist.o: LinkedList/linkedlist.c LinkedList/linkedlist.h
	gcc -c LinkedList/linkedlist.c -o linkedlist.o

clean:
	rm main
	rm *.o
