# If you want to use this on your own machine, change CLASSDIR and/or INCLUDE and LIBS so
# that they point to the correct directories/library.

CLASSDIR = ../Libfdr
INCLUDE = -I$(CLASSDIR)/include
CFLAGS = $(INCLUDE)
LIBS = $(CLASSDIR)/lib/libfdr.a

EXECUTABLES = bin/dllreverse bin/dlltail bin/cos
CC = gcc

all: $(EXECUTABLES)

clean:
	rm -f bin/*

bin/dllreverse: src/dllreverse.c
	$(CC) $(CFLAGS) -o bin/dllreverse src/dllreverse.c $(LIBS)

bin/cos: src/cos.c
	$(CC) $(CFLAGS) -o bin/cos src/cos.c $(LIBS)

bin/dlltail: src/dlltail.c
	$(CC) $(CFLAGS) -o bin/dlltail src/dlltail.c $(LIBS)

