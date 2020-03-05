# Makefile for GTL Testing

CC = gcc
CFLAGS = -g -Wall
default = test

test: test.o queue.o stack.o vector.o linked-list-generic.o linked-list.o
	$(CC) $(CFLAGS) -o test test.o queue.o stack.o vector.o linked-list-generic.o linked-list.o

test.o:	test.c ./vector/vector.c ./vector/vector.h ./stack/stack.h ./stack/stack.c ./queue/queue.h ./queue/queue.c ./linked-list-generic/linked-list-generic.c ./linked-list-generic/linked-list-generic.h ./linked-list/linked-list.c ./linked-list/linked-list.h
	$(CC) $(CFLAGS) -c test.c

queue.o: ./queue/queue.c ./queue/queue.h
	$(CC) $(CFLAGS) -c ./queue/queue.c

stack.o: ./stack/stack.c ./stack/stack.h
	$(CC) $(CFLAGS) -c ./stack/stack.c

vector.o: ./vector/vector.c ./vector/vector.h
	$(CC) $(CFLAGS) -c ./vector/vector.c

linked-list-generic.o: ./linked-list-generic/linked-list-generic.c ./linked-list-generic/linked-list-generic.h
	$(CC) $(CFLAGS) -c ./linked-list-generic/linked-list-generic.c

linked-list.o: ./linked-list/linked-list.c ./linked-list/linked-list.h
	$(CC) $(CFLAGS) -c ./linked-list/linked-list.c

clean:
		$(RM) count *.o *~ test