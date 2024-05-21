INCLUDE = -I include
CFLAGS = $(INCLUDE)
LIBS = lib/libfdr.a
OBJS = obj/dllist.o obj/fields.o obj/jval.o
CC = gcc

all: lib/libfdr.a bin/main

lib/libfdr.a: $(OBJS)
	ar ru lib/libfdr.a $(OBJS)
	ranlib lib/libfdr.a

clean:
	rm -f bin/*
	rm -f obj/*
	rm -f txt/output.txt

obj/fields.o: src/fields.c include/fields.h
	$(CC) $(CFLAGS) -c -o obj/fields.o src/fields.c

obj/jval.o: src/jval.c include/jval.h
	$(CC) $(CFLAGS) -c -o obj/jval.o src/jval.c

obj/dllist.o: src/dllist.c include/dllist.h include/jval.h
	$(CC) $(CFLAGS) -c -o obj/dllist.o src/dllist.c

bin/main: src/main.c $(LIBS)
	$(CC) $(CFLAGS) -o bin/main src/main.c $(LIBS)