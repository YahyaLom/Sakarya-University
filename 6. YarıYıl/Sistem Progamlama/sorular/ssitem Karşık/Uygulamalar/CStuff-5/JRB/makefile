# If you want to use this on your own machine, change CLASSDIR and/or INCLUDE and LIBS so
# that they point to the correct directories/library.

CLASSDIR = ../Libfdr
INCLUDE = -I$(CLASSDIR)/include
CFLAGS = $(INCLUDE)
LIBS = $(CLASSDIR)/lib/libfdr.a

CC = gcc
EXECUTABLES = \
    bin/strsort \
    bin/strrsort1 \
    bin/strrsort2 \
    bin/strisort \
    bin/nsort \
    bin/strusort \
    bin/nsort2 \
    bin/nsort3 \
    bin/golf \
    bin/ni_sort1 \
    bin/ni_sort2 \
    bin/ni_sort3 \

all: $(EXECUTABLES)

clean:
	rm -f bin/*

bin/strsort: src/strsort.c 
	$(CC) $(CFLAGS) -o bin/strsort src/strsort.c $(LIBS)

bin/strrsort1: src/strrsort1.c 
	$(CC) $(CFLAGS) -o bin/strrsort1 src/strrsort1.c $(LIBS)

bin/strrsort2: src/strrsort2.c 
	$(CC) $(CFLAGS) -o bin/strrsort2 src/strrsort2.c $(LIBS)

bin/strusort: src/strusort.c 
	$(CC) $(CFLAGS) -o bin/strusort src/strusort.c $(LIBS)

bin/strisort: src/strisort.c 
	$(CC) $(CFLAGS) -o bin/strisort src/strisort.c $(LIBS)

bin/nsort: src/nsort.c 
	$(CC) $(CFLAGS) -o bin/nsort src/nsort.c $(LIBS)

bin/nsort2: src/nsort2.c 
	$(CC) $(CFLAGS) -o bin/nsort2 src/nsort2.c $(LIBS)

bin/nsort3: src/nsort3.c 
	$(CC) $(CFLAGS) -o bin/nsort3 src/nsort3.c $(LIBS)

bin/ni_sort1: src/ni_sort1.c 
	$(CC) $(CFLAGS) -o bin/ni_sort1 src/ni_sort1.c $(LIBS)

bin/ni_sort2: src/ni_sort2.c 
	$(CC) $(CFLAGS) -o bin/ni_sort2 src/ni_sort2.c $(LIBS)

bin/ni_sort3: src/ni_sort3.c 
	$(CC) $(CFLAGS) -o bin/ni_sort3 src/ni_sort3.c $(LIBS)

bin/golf: src/golf.c 
	$(CC) $(CFLAGS) -o bin/golf src/golf.c $(LIBS)

