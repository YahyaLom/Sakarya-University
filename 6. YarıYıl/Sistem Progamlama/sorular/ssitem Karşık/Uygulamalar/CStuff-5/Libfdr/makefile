# Libraries for fields, doubly-linked lists and red-black trees.
# Copyright (C) 2018 James S. Plank

CFLAGS = -O3 -Iinclude

all: lib/libfdr.a

OBJS = obj/dllist.o obj/fields.o obj/jval.o obj/jrb.o

lib/libfdr.a: $(OBJS)
	ar ru lib/libfdr.a $(OBJS)
	ranlib lib/libfdr.a 

clean:
	rm -f obj/* lib/*

obj/fields.o: src/fields.c include/fields.h
	gcc $(CFLAGS) -c -o obj/fields.o src/fields.c

obj/jval.o: src/jval.c include/jval.h
	gcc $(CFLAGS) -c -o obj/jval.o src/jval.c

obj/dllist.o: src/dllist.c include/dllist.h include/jval.h
	gcc $(CFLAGS) -c -o obj/dllist.o src/dllist.c

obj/jrb.o: src/jrb.c include/jrb.h include/jval.h
	gcc $(CFLAGS) -c -o obj/jrb.o src/jrb.c
